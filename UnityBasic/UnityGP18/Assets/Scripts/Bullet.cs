using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bullet : MonoBehaviour
{
    public Vector3 vStartPos;
    public float Dist;
    public Player master;

    // Start is called before the first frame update
    void Start()
    {
        vStartPos = transform.position;
    }

    // Update is called once per frame
    void Update()
    {
        Vector3 vPos = this.transform.position;
        //Vector3 vDist = vPos - vStartPos;
        //float fDist = vDist.magnitude;
        float fDist = Vector3.Distance(vStartPos, vPos);
        if (fDist > Dist)
            Destroy(gameObject);
    }

    private void FixedUpdate()
    {
        Vector3 vPos = this.transform.position;
        int nLayer = LayerMask.NameToLayer("Monster");

        CircleCollider2D circleCollider = GetComponent<CircleCollider2D>();
        vPos += new Vector3(circleCollider.offset.x, circleCollider.offset.y, 0);

        Collider2D collider = Physics2D.OverlapCircle(vPos, circleCollider.radius, 1 << nLayer);

        if (collider)
        {
            Player player = master;
            Player target = collider.gameObject.GetComponent<Player>();
            SuperMode superMode = target.GetComponent<SuperMode>();
            if (superMode && superMode.isOn == false)
            {
                player.Attack(target);
                superMode.Active();
            }
        }
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.tag == "Monster")
            Destroy(collision.gameObject);
    }
}
