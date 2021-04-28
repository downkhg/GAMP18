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

    // Start is called before the first frame update
    void Start()
    {
        instance = this;
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
