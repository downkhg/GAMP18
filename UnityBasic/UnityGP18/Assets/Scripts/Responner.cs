using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Responner : MonoBehaviour
{
    public GameObject m_prefabPlayer;
    public GameObject m_objPlayer;
    public bool isRespon = false;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if(m_objPlayer == null && isRespon == false)
        {
            //게임오브젝트가 없으므로 복제에 실패한다.
            //Instantiate(m_prefabPlayer);
            //m_objPlayer = Instantiate(m_prefabPlayer);
            //m_objPlayer.transform.position = this.transform.position;
            StartCoroutine(ProcessResponTimmer());
        }
    }

    IEnumerator ProcessResponTimmer()
    {
        Debug.Log("ProcessResponTimmer start");
        isRespon = true;
        yield return new WaitForSeconds(1);
        ResponPlayer();
        isRespon = false;
        Debug.Log("ProcessResponTimmer end");
    }

    void ResponPlayer()
    {
        m_objPlayer = Instantiate(m_prefabPlayer);
        m_objPlayer.transform.position = this.transform.position;
    }
}
