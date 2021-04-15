﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    public Responner responnerPlayer;
    public Responner responnerOpossum;
    public Responner responnerEagle;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        GameObject objEagle = responnerEagle.m_objPlayer;

        if(objEagle)
        {
            Eagle eagle = objEagle.GetComponent<Eagle>();
            eagle.responner = responnerEagle;
        }
    }
}
