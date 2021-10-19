using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;
//찾기->발견(회전)->이동->사거리->공격->타겟X->찾기
public class AIController : Controller
{
    public GameObject m_objTarget;
    public float m_fSite;
    public float m_fSiteAngle;

    public float m_fShotDist;
    public float m_fTime;

    public bool m_isMove;
    public bool m_isInArea;

    public enum E_AI_STATE { FIND, LOOKAT, MOVE, ATTACK }
    public E_AI_STATE m_eCurState;
    public void SetState(E_AI_STATE state)
    {
        Debug.Log("SetState:"+state);
        switch (state)
        {
            case E_AI_STATE.FIND:
                break;
            case E_AI_STATE.LOOKAT:
                LookAtTarget();
                break;
            case E_AI_STATE.MOVE:
                break;
            case E_AI_STATE.ATTACK:
                m_fCurTime = 0;
                m_dynamicPlayer.Shot(m_strTargetTag);
                break;
        }
        m_eCurState = state;
    }

    public void UpdateState()
    {
        switch (m_eCurState)
        {
            case E_AI_STATE.FIND:
                if(m_objTarget)
                    SetState(E_AI_STATE.LOOKAT);
                break;
            case E_AI_STATE.LOOKAT:
                SetState(E_AI_STATE.MOVE);
                break;
            case E_AI_STATE.MOVE:
                if (m_objTarget)
                {
                    if (ProcessMove() == false)
                        SetState(E_AI_STATE.ATTACK);
                }
                else
                    SetState(E_AI_STATE.FIND);
                break;
            case E_AI_STATE.ATTACK:
                if (m_objTarget)
                    AttackShot();
                else
                    SetState(E_AI_STATE.FIND);
                break;
        }
    }

    IEnumerator ProcessTime(float time)
    {
        while(!m_isMove)
        {
            m_dynamicPlayer.Shot(m_strTargetTag);
            yield return new WaitForSeconds(time);
        }
    }

    private void OnDrawGizmos()
    {
        Gizmos.DrawWireSphere(this.transform.position, m_fSite);
    }

    private void OnGUI()
    {
        GUI.Box(new Rect(0, 0, 100, 20), "Time:"+m_fCurTime);
        GUI.Box(new Rect(0, 20, 100, 20), "State:" + m_eCurState);
    }

    bool ArcColCheck(Transform target, Vector3 forword, float angle, float rad)
    {
        Vector3 vPos = transform.position;
        Vector3 vTargetPos = target.position;
        Vector3 vTargetDist = vTargetPos - vPos;
        float fDist = vTargetDist.magnitude;
        float fHalfAngle = angle * 0.5f;
        
        float fAngle = Vector3.Angle(forword, vTargetDist.normalized);

        Vector3 vRight = forword;
        Vector3 vLeft = forword;

        Quaternion qRotR = Quaternion.AngleAxis(fHalfAngle, Vector3.up);
        Quaternion qRotL = Quaternion.AngleAxis(fHalfAngle, Vector3.down);

        vRight = qRotR * vRight;
        vLeft = qRotL * vLeft;

        Vector3 vStartForword = vPos;
        Vector3 vEndForword = vStartForword + forword * rad;
        Debug.DrawLine(vStartForword, vEndForword, Color.blue);

        Vector3 vStartRight = vPos;
        Vector3 vEndRight = vStartRight + vRight * rad;
        Debug.DrawLine(vStartRight, vEndRight, Color.red);

        Vector3 vStartLeft = vPos;
        Vector3 vEndLeft = vStartLeft + vLeft * rad;
        Debug.DrawLine(vStartLeft, vEndLeft, Color.red);

        Debug.DrawLine(vPos, vTargetPos, Color.green);

        if (fDist <= rad && fAngle <= fHalfAngle)
            return true;

        return false;
    }

    public float m_fCurTime = -1;
    public float m_fMaxTime = 1;

    public void AttackShot()
    {
        if (m_objTarget)
        {
            if (!m_isMove)
            {
                if (m_fCurTime >= 0)
                    m_fCurTime += Time.deltaTime;

                //0~0.9 0
                if (m_fCurTime >= m_fMaxTime)
                {
                    //Debug.Log("ShotTime!!");
                    m_dynamicPlayer.Shot(m_strTargetTag);
                    m_fCurTime -= m_fMaxTime;
                }
            }
            else
                m_fCurTime -= 1;
        }
    }

    public bool ProcessMove()
    {
        Vector3 vTarget = m_objTarget.transform.position;
        Vector3 vPos = this.gameObject.transform.position;

        if (m_fShotDist < Vector3.Distance(vTarget, vPos))
        {
            //m_dynamicPlayer.Move(transform, Vector3.forward);
            GetComponent<NavMeshAgent>().SetDestination(vTarget);
            m_isMove = true;
            return true;
        }
        else
        {
            //m_fCurTime = 0;
            m_isMove = false;
            return false;
        }
    }

    public void LookAtTarget()
    {
        Vector3 vTargetPos = m_objTarget.transform.position;
        vTargetPos.y = 0;
        //Debug.Log("LookAtTarget:"+m_objTarget.name);
        transform.LookAt(m_objTarget.transform.parent);
    }

    public bool FindTargetProcess(string TargetTag)
    {
        Collider[] collideres = Physics.OverlapSphere(transform.position, m_fSite);

        for (int i = 0; i < collideres.Length; i++)
        {
            if (collideres[i].tag == TargetTag)
            {
                if (ArcColCheck(collideres[i].transform, transform.forward, m_fSiteAngle, m_fSite))
                {
                    m_objTarget = collideres[i].gameObject;
                    LookAtTarget();
                    return true;
                }
            }
        }
        
        return false;
    }

    private void FixedUpdate()
    {
        if (!FindTargetProcess(m_strTargetTag))
        {
            

            m_objTarget = null;
        }
    }

    // Update is called once per frame
    void Update()
    {
        UpdateState();
    }
}
