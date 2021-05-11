using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class GameManager : MonoBehaviour
{
    public Responner responnerPlayer;
    public Responner responnerOpossum;
    public Responner responnerEagle;

    public CameraTracker cameraTracker;

    public int LifeCount = 0;

    public Sprite spriteKillMounster;
    //싱글톤
    static GameManager instance;

    public static GameManager GetInstance()
    {
        return instance;
    }

    public enum E_SCENE_STATE { NONE = -1, TITLE, PLAY, GAMEOVER, THEEND }
    public E_SCENE_STATE m_eCurState = E_SCENE_STATE.NONE;
    public List<GameObject> m_listScenes;

    public Text textLv;
    public Text textName;

    public RectTransform rectHPBar;
    public RectTransform rectHPBarBG;

    public GUIStatusBar guiExpBar;

    public Image imgKillMonster;

    public float NowTime = -1;
    public float MaxTime = 60;

    public void SetHPBar(float hp, float maxhp)
    {
        float fRat = hp / maxhp;
        Vector2 vSize = rectHPBar.sizeDelta;
        vSize.x = rectHPBarBG.sizeDelta.x * fRat; 
        rectHPBar.sizeDelta = vSize;
    }

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
        //if (m_eCurState == state) return;
        switch (state)
        {
            case E_SCENE_STATE.TITLE:
                Time.timeScale = 0;
                break;
            case E_SCENE_STATE.PLAY:
                Time.timeScale = 1;
                EventReset();
                NowTime = 0;
                break;
            case E_SCENE_STATE.GAMEOVER:
                imgKillMonster.sprite = spriteKillMounster;
                Time.timeScale = 0;
                break;
            case E_SCENE_STATE.THEEND:
                Time.timeScale = 0;
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
                {
                    //플레이어가 3번죽으면 게임오버로 변경하기.
                    //if (responnerPlayer.m_objPlayer == null)
                    //    SetState(E_SCENE_STATE.GAMEOVER);
                    GameObject objPlayer = responnerPlayer.m_objPlayer;
                    if (objPlayer)
                    {
                        Player player = objPlayer.GetComponent<Player>();
                        if (player)
                        {
                            SetHPBar(player.m_nHP, player.m_nMaxHP);
                            guiExpBar.SetBar(player.m_nExp, 100);
                            textLv.text = string.Format("Lv. {0}",player.m_nLv);
                            textName.text = objPlayer.name;
                        }
                    }

                    if(LifeCount <= 0)
                    {
                        SetState(E_SCENE_STATE.GAMEOVER);
                    }

                    if (NowTime >= 0)
                    {
                        NowTime += Time.deltaTime;

                        if (NowTime >= MaxTime)
                        {
                            NowTime = -1;
                            SetState(E_SCENE_STATE.GAMEOVER);
                        }
                    }
                }
                break;
            case E_SCENE_STATE.GAMEOVER:
                
                break;
            case E_SCENE_STATE.THEEND:
                break;
        }
    }

    public void EventReset()
    {
        Destroy(responnerPlayer.m_objPlayer);
        Destroy(responnerEagle.m_objPlayer);
        Destroy(responnerOpossum.m_objPlayer);
        cameraTracker.ResetPos(responnerPlayer.transform.position);
        //SceneManager.LoadScene("game"); //기존씬정보가 저장되지않아 문제가 발생함.
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
        UpdateState();

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

    private void OnGUI()
    {
        GUI.Box(new Rect(0, 0, 200, 20), string.Format("Time:{0}/{1}",NowTime,MaxTime));
    }
}
