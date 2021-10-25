using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.EventSystems;

public class GUIItem : MonoBehaviour, IPointerDownHandler, IPointerUpHandler
{
    [SerializeField]
    Text m_textName;
    [SerializeField]
    Image m_imgIcon;
    [SerializeField]
    GUIItemInfo m_guiItenInfo;
    [SerializeField]
    Item m_cItem;

    public GUIItemInfo ItemInfo
    {
        get { return m_guiItenInfo; }
        //set { m_guiItenInfo = value; }
    }

    public void OnPointerDown(PointerEventData eventData)
    {
        m_guiItenInfo.SetInfo(m_cItem);
        m_guiItenInfo.Show(true);
    }

    public void OnPointerUp(PointerEventData eventData)
    {
        m_guiItenInfo.Show(false);
    }

    public void SetItemInfo(Item item, GUIItemInfo gUIItemInfo)
    {
        m_textName.text = item.Name;
        m_imgIcon.sprite = Resources.Load<Sprite>("Icon/"+item.Name);
        m_cItem = item;
        m_guiItenInfo = gUIItemInfo;
    }
}
