using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DeathZone : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    private void OnCollisionStay2D(Collision2D collision)
    {
        Destroy(collision.gameObject);
        //Instantiate(collision.gameObject);//삭제된 대상을 복제하면안된다.

    }

    private void OnTriggerStay2D(Collider2D collision)
    {
        Destroy(collision.gameObject);
        //Instantiate(collision.gameObject);//삭제된 대상을 복제하면안된다.
    }
}
