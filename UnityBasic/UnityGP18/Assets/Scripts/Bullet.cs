using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bullet : MonoBehaviour
{
    public Vector3 vStartPos;
    public float Dist;
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

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.tag == "Monster")
            Destroy(collision.gameObject);
    }
}
