using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    [SerializeField]
    List<Controller> m_listController;
    [SerializeField]
    List<ItemObject> m_listItemObject;
    [SerializeField]
    ItemManager m_cItemManager;

    static GameManager m_instance;

    public static GameManager GetInstance()
    {
        return m_instance;
    }

    private void Awake()
    {
        m_instance = this;
    }

    public ItemManager GetItemManager() { return m_cItemManager; }

    public void ItemGenerator(Vector3 pos)
    {
        GameObject prefabs =  Resources.Load("Prefabs/Item") as GameObject;
        GameObject objItem = Instantiate(prefabs);
        ItemObject itemObject = objItem.GetComponent<ItemObject>();
        itemObject.Item = GameManager.GetInstance().m_cItemManager.GetItem(ItemManager.eItem.HPPotion);
    }

    // Start is called before the first frame update
    void Start()
    {
        m_cItemManager = GetComponent<ItemManager>();
        m_listItemObject[0].Item = 
            m_cItemManager.GetItem(ItemManager.eItem.BoneSword);
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
