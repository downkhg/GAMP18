using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SuperMode : MonoBehaviour
{
    public bool isOnStart;
    public bool isOn;
    public float Time;
    IEnumerator ProcessTimmer()
    {
        Debug.Log("ProcessTimmer start"); //1
        isOn = true; //2
        yield return new WaitForSeconds(Time);//지정한 옵션만큼 대기한다.
        isOn = false;
        this.GetComponent<SpriteRenderer>().color = Color.white;
        Debug.Log("ProcessTimmer end"); //5
    }
    public void Active()
    {
        StartCoroutine(ProcessTimmer());
    }
    void Start()
    {
        if(isOnStart) Active();
    }
    void Update()
    {
        if (isOn)
        {
            SpriteRenderer spriteRenderer = GetComponent<SpriteRenderer>();
            Color color = spriteRenderer.color;
            if (color.a == 1) color.a = 0;
            else color.a = 1;
            spriteRenderer.color = color;
        }
    }
}
