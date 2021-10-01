using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Controller : MonoBehaviour
{
    [SerializeField]
    protected string m_strTargetTag;
    public Dynamic m_dynamicPlayer;

    private void OnCollisionEnter(Collision collision)
    {
        Debug.Log("OnCollisionEnter 1:" + collision.gameObject.name);
        m_dynamicPlayer. m_isJump = false;
        Debug.Log("OnCollisionEnter 2:" + collision.gameObject.name);
    }
}
