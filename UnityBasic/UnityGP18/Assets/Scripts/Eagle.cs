using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Eagle : MonoBehaviour
{
    public float Speed = 1;
    public float Site = 0.5f;

    public GameObject objTarget;

    public Responner responner;
    public Transform patrolPoint;

    public enum E_AI_STATUS { RETURN, PATROL ,ATTACK}
    public E_AI_STATUS m_eCurAIStatus = E_AI_STATUS.RETURN;

    public void SetAIStaus(E_AI_STATUS status)
    {
        switch(status)
        {
            case E_AI_STATUS.RETURN:
                break;
            case E_AI_STATUS.PATROL:
                break;
            case E_AI_STATUS.ATTACK:
                break;
        }
        m_eCurAIStatus = status;
    }

    public void UpdateAIStatus()
    {
        switch (m_eCurAIStatus)
        {
            case E_AI_STATUS.RETURN:
                if (ProcessReturn() == false)
                    SetAIStaus(E_AI_STATUS.PATROL);
                break;
            case E_AI_STATUS.PATROL:
                ProcessPatrol();
                break;
            case E_AI_STATUS.ATTACK:
                if (objTarget == null)
                    SetAIStaus(E_AI_STATUS.RETURN);
                break;
        }
    }

    // Start is called before the first frame update
    void Start()
    {
        SetAIStaus(m_eCurAIStatus);
    }

    void ProcessPatrol()
    {
        if (patrolPoint == null || objTarget == null) return;
        if(NearCheckPostion(objTarget.transform.position))
        {
            if (objTarget.name == responner.gameObject.name)
            {
                objTarget = patrolPoint.gameObject;
            }
            else if (objTarget.name == patrolPoint.gameObject.name)
            {
                objTarget = responner.gameObject;
            }
        }
    }

    bool ProcessReturn()
    {
        if (objTarget)
        {
            ProcessPatrol();
            return false;
        }
        else
        {
            if (responner != null && objTarget == null)
                objTarget = responner.gameObject;
        }

        return true;
    }

    bool ProcessFindTarget()
    {
        Vector3 vPos = this.transform.position;
        int nLayer = LayerMask.NameToLayer("Player");
        Collider2D collider = Physics2D.OverlapCircle(vPos, Site,1<< nLayer);

        if (collider)
        {
            Debug.Log(collider.gameObject.name);
            objTarget = collider.gameObject;
            SetAIStaus(E_AI_STATUS.ATTACK);
        }
         else
        {
            if (objTarget && objTarget.layer == nLayer)
            {
                objTarget = null;
                return false;
            }
        }

        return true;
    }

    bool NearCheckPostion(Vector3 vTagetPos)
    {
        float fDist = Vector3.Distance(transform.position, vTagetPos);
        float fMoveDist = Speed * Time.deltaTime;
        if (fDist > fMoveDist)
        {
            return false;
        }
        else
            return true;
    }

    bool MoveProcess(Vector3 vPos, Vector3 vTagetPos)
    {
        Vector3 vDist = vTagetPos - vPos;
        Vector3 vDir = vDist.normalized;

        float fDist = vDist.magnitude;
        float fMoveDist = Speed * Time.deltaTime;

        if (fDist > fMoveDist)
        {
            transform.position += vDir * Speed * Time.deltaTime;
            return true;
        }
        else
            return false;
    }

    private void FixedUpdate()
    {
        if (ProcessFindTarget() == false)
            SetAIStaus(E_AI_STATUS.RETURN);
        //ProcessDemage();
    }

    void ProcessDemage()
    {
        SuperMode superMode = GetComponent<SuperMode>();
        if (superMode != null && superMode.isOn) return;

        Vector3 vPos = this.transform.position;
        int nLayer = LayerMask.NameToLayer("Bullet");

        CircleCollider2D circleCollider = GetComponent<CircleCollider2D>();
        vPos += new Vector3(circleCollider.offset.x, circleCollider.offset.y, 0);

        Collider2D collider = Physics2D.OverlapCircle(vPos, circleCollider.radius, 1 << nLayer);

        if (collider)
        {
            //GameObject objPlayer =  GameObject.Find("Player"); //검색을 하기위해 게임오브젝트를 검색해야하므로 추천하지않음.
            GameObject objPlayer = GameManager.GetInstance().responnerPlayer.m_objPlayer;//싱글톤을 이용한 플레이어에 접근
            if (objPlayer)
            {
                Player player = objPlayer.GetComponent<Player>();
                Player target = this.gameObject.GetComponent<Player>();

                player.Attack(target);
                superMode.Active();
                GameManager.GetInstance().spriteKillMounster = 
                    target.GetComponent<SpriteRenderer>().sprite;
            }
        }
    }


    private void OnDrawGizmos()
    {
        Gizmos.DrawWireSphere(this.transform.position, Site);
    }

    // Update is called once per frame
    void Update()
    {
        if (objTarget)
            MoveProcess(this.transform.position, objTarget.transform.position);

        //ProcessReturn();
        UpdateAIStatus();
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        Destroy(collision.gameObject);
    }
    ////트리거는 총알에 맞아도 반응하므로 사용할수없다.
    //private void OnTriggerStay2D(Collider2D collision)
    //{
    //    //플레이어의 위치를 받아와? 따라가게만든다?
    //    Vector3 vPos = this.transform.position;
    //    Vector3 vTagetPos = collision.transform.transform.position;

    //    Vector3 vDist = vTagetPos - vPos;
    //    Vector3 vDir = vDist.normalized;

    //    transform.position += vDir * Speed * Time.deltaTime;
    //}
}
