using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GUIItemInfo : MonoBehaviour
{
    [SerializeField]
    Text m_textName;
    [SerializeField]
    Text m_textComment;

    public void SetInfo(Item item)
    {
        m_textName.text = item.Name;
        m_textComment.text = item.Comment;
    }

    public void Show(bool show)
    {
        if (show) gameObject.SetActive(true);
        else gameObject.SetActive(false);
    }

    private void FixedUpdate()
    {
        RectTransform rectTransform = GetComponent<RectTransform>();
        rectTransform.transform.position = Input.mousePosition;
    }
}
