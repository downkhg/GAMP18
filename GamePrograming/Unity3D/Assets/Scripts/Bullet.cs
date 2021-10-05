using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bullet : MonoBehaviour
{
    string m_strTargetTag;

    public string TargetTag 
    {
        set { m_strTargetTag = value; }
        get { return m_strTargetTag; }
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.tag == m_strTargetTag)
        {
            other.transform.parent.gameObject.SetActive(false);
        }
    }
}
