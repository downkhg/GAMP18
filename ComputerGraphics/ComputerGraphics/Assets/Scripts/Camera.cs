using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Camera : MonoBehaviour
{
    public Transform trTarget;
    public Vector3 vAsix = Vector3.right;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        Vector3 vTargetPos =  trTarget.position;
        Vector3 vCamPos = this.transform.position;

        Vector3 vDist = vCamPos - vTargetPos;
        Vector3 vDir = vDist.normalized;
        float fDist = vDist.magnitude;

        Quaternion rotateCam = Quaternion.Euler(vAsix * Time.deltaTime);

        vDir = rotateCam * vDir;

        transform.position = vTargetPos + vDir * fDist;

        transform.LookAt(trTarget);
    }
}
