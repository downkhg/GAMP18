using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GUIStatusBar : MonoBehaviour
{
    public RectTransform rectBar;
    public RectTransform rectBarBG;

    public void SetBar(float state, float maxState)
    {
        float fRat = state / maxState;
        Vector2 vSize = rectBar.sizeDelta;
        vSize.x = rectBarBG.sizeDelta.x * fRat;
        rectBar.sizeDelta = vSize;
    }
}
