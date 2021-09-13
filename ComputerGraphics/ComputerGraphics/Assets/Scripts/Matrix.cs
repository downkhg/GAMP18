using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Matrix : MonoBehaviour
{
    public Transform targetAxis;//축을 계산하기위한 오브젝트
    public Vector3 m_vAsix = Vector3.up;
    public float m_fRatAngle;
    // Start is called before the first frame update
    void Start()
    {
        Matrix4x4 temp = transform.localToWorldMatrix * transform.worldToLocalMatrix;
        Debug.Log(temp);
    }

    // Update is called once per frame
    void Update()
    {
        if(targetAxis)//타겟축이 없다면 설정된 축으로 회전한다.
        { 
            Vector3 vTargetPos = targetAxis.position;
            Vector3 vPos = transform.position;
            //타겟과 현재 오브젝트의 위치를 계산하여 축을 생성
        
            m_vAsix = (vTargetPos - vPos).normalized;
        }

        transform.Rotate(m_vAsix * m_fRatAngle * Time.deltaTime);

        Debug.DrawLine(transform.position, targetAxis.position, Color.red); 
    }
    public int idx = 0;
    private void OnGUI()
    {
        int w = 300;
        int h = 100;
        int a = 0;
        GUI.Box(new Rect(w * idx, a * h, w, h), 
            gameObject.name + "\n"+ transform.localToWorldMatrix.ToString()); a++;
        GUI.Box(new Rect(w * idx, a * h, w, h), 
            transform.worldToLocalMatrix.ToString()); a++;
    }
}
