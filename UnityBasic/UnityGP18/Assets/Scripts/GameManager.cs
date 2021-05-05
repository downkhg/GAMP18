using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    public Responner responnerPlayer;
    public Responner responnerOpossum;
    public Responner responnerEagle;

    public CameraTracker cameraTracker;
    //싱글톤
    static GameManager instance;

    public static GameManager GetInstance()
    {
        return instance;
    }

    public enum E_SCENE_STATE { TITLE, PLAY, GAMEOVER, THEEND } 
    public E_SCENE_STATE m_eCurState;
    public List<GameObject> m_listScenes; 

    void ShowScene(E_SCENE_STATE state)
    {
        for (int i = 0; i < m_listScenes.Count; i++)
        {
            if(i == (int)state)
                m_listScenes[i].SetActive(true);
            else
                m_listScenes[i].SetActive(false);
        }
    }

    void SetState(E_SCENE_STATE state)
    {
        switch (state)
        {
            case E_SCENE_STATE.TITLE:
                break;
            case E_SCENE_STATE.PLAY:
                break;
            case E_SCENE_STATE.GAMEOVER:
                break;
            case E_SCENE_STATE.THEEND:
                break;
        }
        ShowScene(state);
        m_eCurState = state;
    }
    void UpdateState()
    {
        switch (m_eCurState)
        {
            case E_SCENE_STATE.TITLE:
                break;
            case E_SCENE_STATE.PLAY:
                break;
            case E_SCENE_STATE.GAMEOVER:
                break;
            case E_SCENE_STATE.THEEND:
                break;
        }
    }

    public void EventSceneChange(int sceneNumber)
    {
        Debug.Log("EventSceneChange:"+sceneNumber);
        SetState((E_SCENE_STATE)sceneNumber);
    }

    public void EventExit()
    {
        Debug.Log("EventExit");
        Application.Quit();
    }

    // Start is called before the first frame update
    void Start()
    {
        instance = this;
        SetState(m_eCurState);
    }

    // Update is called once per frame
    void Update()
    {
        GameObject objEagle = responnerEagle.m_objPlayer;

        if(objEagle)
        {
            Eagle eagle = objEagle.GetComponent<Eagle>();
            if (eagle.responner == null)
                eagle.responner = responnerEagle;

            if(eagle.patrolPoint == null)
                eagle.patrolPoint = responnerOpossum.transform;
        }

        if(cameraTracker.objTarget == null)
            cameraTracker.objTarget = responnerPlayer.m_objPlayer;
    }
}
