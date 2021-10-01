using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AIController : Controller
{
    public GameObject m_objTarget;
    public float m_fSite;
    public float m_fShotDist;

    private void OnDrawGizmos()
    {
        Gizmos.DrawWireSphere(this.transform.position, m_fSite);
    }

    public void ProcessMove()
    {
        if(m_objTarget)
        {
            Vector3 vTarget = m_objTarget.transform.position;
            Vector3 vPos = this.gameObject.transform.position;

            if(m_fShotDist < Vector3.Distance(vTarget,vPos) )
                m_dynamicPlayer.Move(transform, Vector3.forward);
        }
    }

    public void LookAtTarget()
    {
        Debug.Log("LookAtTarget:"+m_objTarget.name);
        transform.LookAt(m_objTarget.transform);
    }

    public void FindTargetProcess(string TargetTag)
    {
        Collider[] collideres = Physics.OverlapSphere(transform.position, m_fSite);

        for(int i = 0; i < collideres.Length; i++)
        {
            if(collideres[i].tag == TargetTag)
            {
                m_objTarget = collideres[i].gameObject;
                LookAtTarget();
                break;
            }
        }
    }

    private void FixedUpdate()
    {
        FindTargetProcess(m_strTargetTag);
    }

    // Update is called once per frame
    void Update()
    {
        ProcessMove();
    }
}
