using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Responner : MonoBehaviour
{
    public GameObject objPlayer;
    public float m_fTime = 1;
    IEnumerator ProcessTime()
    {
        Debug.Log("Death:" + objPlayer.name);
        yield return new WaitForSeconds(m_fTime);
        Debug.Log("Respon:"+objPlayer.name);
        objPlayer.SetActive(true);
        objPlayer.transform.position = this.transform.position;
    }

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if(objPlayer.activeSelf == false)
        {
            StartCoroutine(ProcessTime());
        }
    }
}
