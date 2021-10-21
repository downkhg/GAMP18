using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ItemObject : MonoBehaviour
{
    [SerializeField]
    Item m_cItem;

    public Item Item
    {
        get { return m_cItem; }
        set { m_cItem = value; }
    }

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    private void OnTriggerEnter(Collider other)
    {
        Debug.Log("1.OnTriggerEnter:"+other.gameObject.name);
        if (other.gameObject.tag == "Player")
        {
            GameObject objPlayer = other.gameObject;
            Player player = objPlayer.GetComponent<Player>();
            Debug.Log("2.OnTriggerEnter:" + other.gameObject.name);
            if (player)
            {
                Debug.Log("3.OnTriggerEnter:" + other.gameObject.name);
                player.SetInvetory(m_cItem);
                Destroy(gameObject);
            }
        }
    }
}
