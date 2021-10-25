using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GUIInventory : MonoBehaviour
{
    [SerializeField]
    List<GUIItem> m_listItems = new List<GUIItem>();
    [SerializeField]
    GUIItemInfo m_guiItemInfo;

    public void InitIventory(Player player)
    {
        GameObject prefabsItem = Resources.Load("GUI/Item") as GameObject;
        List<Item> items = player.Invetory;
        for (int i = 0;  i < items.Count; i++ )
        {
            GameObject objItem = Instantiate(prefabsItem);
            GUIItem gUIItem = objItem.GetComponent<GUIItem>();
            gUIItem.SetItemInfo(items[i], m_guiItemInfo);
        }
    }

    public void Start()
    {
        Debug.Log("GUIInventory::Start()");
        InitIventory(GameManager.GetInstance().GetPlayer(0));
    }
}
