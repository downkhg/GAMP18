using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Eagle : MonoBehaviour
{
    public float Speed = 1;
    public float Site = 0.5f;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    //private void FixedUpdate()
    //{
    //    Vector3 vPos = this.transform.position;
    //    Collider2D[] colliders = Physics2D.OverlapCircleAll(vPos, 0.5f);

    //    if(colliders.Length > 0)
    //    {
    //        Debug.Log("CollidersCount:"+colliders.Length);
    //        foreach (Collider2D collider in colliders)
    //        {
    //            if (collider.tag == "Player")
    //            {
    //                Debug.Log(collider.gameObject.name);
    //                Vector3 vTagetPos = collider.transform.transform.position;

    //                Vector3 vDist = vTagetPos - vPos;
    //                Vector3 vDir = vDist.normalized;

    //                transform.position += vDir * Speed * Time.deltaTime;
    //            }
    //        }
    //    }
    //}

    private void FixedUpdate()
    {
        Vector3 vPos = this.transform.position;
        int nLayer = 1 << LayerMask.NameToLayer("Player");
        Collider2D collider = Physics2D.OverlapCircle(vPos, Site, nLayer);

        if (collider)
        {
            Debug.Log(collider.gameObject.name);
            Vector3 vTagetPos = collider.transform.transform.position;

            Vector3 vDist = vTagetPos - vPos;
            Vector3 vDir = vDist.normalized;

            transform.position += vDir * Speed * Time.deltaTime;
        }
    }

    private void OnDrawGizmos()
    {
        Gizmos.DrawWireSphere(this.transform.position, Site);
    }

    // Update is called once per frame
    void Update()
    {
        
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
