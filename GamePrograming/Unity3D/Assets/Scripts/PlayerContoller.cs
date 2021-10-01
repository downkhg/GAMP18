using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerContoller : Controller
{
    void Update()
    {
        if (Input.GetKey(KeyCode.UpArrow))
            transform.Translate(Vector3.forward * m_dynamicPlayer.m_fSpeed * Time.deltaTime);
        if (Input.GetKey(KeyCode.DownArrow))
            transform.Translate(Vector3.back * m_dynamicPlayer.m_fSpeed * Time.deltaTime);
        if (Input.GetKey(KeyCode.RightArrow))
            transform.Rotate(Vector3.up);
        if (Input.GetKey(KeyCode.LeftArrow))
            transform.Rotate(Vector3.down);

        if (Input.GetKeyDown(KeyCode.Space))
        {
            m_dynamicPlayer.Jump(GetComponent<Rigidbody>());
        }

        if (Input.GetKeyDown(KeyCode.X))
        {
            m_dynamicPlayer.Shot(m_strTargetTag);
        }
    }
}
