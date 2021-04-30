using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraTracker : MonoBehaviour
{
    public GameObject objTarget;
    public float Speed = 1;

    bool MoveProcess(Vector3 vPos, Vector3 vTagetPos)
    {
        vTagetPos.z = vPos.z;
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

    void MoveLerpProcess(Vector3 vPos, Vector3 vTagetPos)
    {
        vTagetPos.z = vPos.z;
        transform.position = Vector3.Lerp(vPos, vTagetPos, 0.5f);
    }

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        //MoveProcess(this.transform.position, objTarget.transform.position);
        MoveLerpProcess(this.transform.position, objTarget.transform.position);
    }
}
