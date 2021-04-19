using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Responner : MonoBehaviour
{
    public GameObject m_objPlayer;
    public string m_strPlayer;
    public bool isRespon = false;
    public float ResponTime = 1;
    // Start is called before the first frame update
    void Start()
    {
        //시작할때 지정된 오브젝트의 이름을 저장한다.
        m_strPlayer = m_objPlayer.name;
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

        //if(m_objPlayer)
        //{
        //    Eagle eagle = m_objPlayer.GetComponent<Eagle>();
        //    if (eagle)
        //        eagle.responner = this;
        //}
    }

    IEnumerator ProcessResponTimmer()
    {
        Debug.Log("ProcessResponTimmer start"); //1
        isRespon = true; //2
        yield return new WaitForSeconds(ResponTime);//지정한 옵션만큼 대기한다.
        ResponPlayer(); //3
        isRespon = false;
        Debug.Log("ProcessResponTimmer end"); //5
    }

    void ResponPlayer()
    {
        GameObject prefabPlayer = Resources.Load("Prefabs/"+ m_strPlayer) as GameObject;
        m_objPlayer = Instantiate(prefabPlayer);
        m_objPlayer.transform.position = this.transform.position;
    }
}
