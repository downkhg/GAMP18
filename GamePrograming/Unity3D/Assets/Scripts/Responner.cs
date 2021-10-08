using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Responner : MonoBehaviour
{
    public GameObject objPlayer;
    public float m_fTime = 1;
    public bool m_isRespon;
    IEnumerator ProcessTime()
    {
        m_isRespon = true;
        Debug.Log("Death:" + objPlayer.name);
        objPlayer.transform.position = this.transform.position;
        yield return new WaitForSeconds(m_fTime);
        //Debug.Log("Respon:"+objPlayer.name);
        objPlayer.SetActive(true);
        m_isRespon = false;
    }

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if(objPlayer.activeSelf == false && m_isRespon == false)
        {
            StartCoroutine(ProcessTime());
        }
    }
}
