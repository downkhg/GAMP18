using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Item : MonoBehaviour
{
    public int Score;
    // Start is called before the first frame update
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {

    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        Debug.Log("OnTriggerEnter2D:"+collision.gameObject.name);
        //if (collision.gameObject.name == "player")
        if (collision.gameObject.tag == "Player")//대소문자 구별함.
        {
            Dynamic dynamic = collision.gameObject.GetComponent<Dynamic>();
            if (dynamic != null)
            {
                dynamic.Score += Score;
                Destroy(gameObject);
            }
            else //만약, 대상에 해당 컴포넌트가 없다면 null이 된다.
                Debug.Log("dynamic is null!!");
        }
    }
}
