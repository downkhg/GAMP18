using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Dynamic : MonoBehaviour
{
    public float JumpPower;
    public bool isJump = false;
    public int Score;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        //transform.position += Vector3.right * Time.deltaTime;

        if (Input.GetKey(KeyCode.RightArrow))
            transform.position += Vector3.right * Time.deltaTime;
        //왼쪽으로 이동하기 추가해보기.
        if (Input.GetKey(KeyCode.LeftArrow))
            transform.position += Vector3.left * Time.deltaTime;

        if (Input.GetKeyDown(KeyCode.Space))
        {
            if (isJump == false)
            {
                Rigidbody2D rigidbody2D = GetComponent<Rigidbody2D>();
                rigidbody2D.AddForce(Vector3.up * JumpPower);
                isJump = false;
            }
        }
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        isJump = false;
        Debug.Log("OnCollisionEnter2D:"+collision.gameObject.name);
    }

    private void OnCollisionExit2D(Collision2D collision)
    {
        //isGround = false;
        Debug.Log("OnCollisionExit2D:" + collision.gameObject.name);
    }

    private void OnGUI()
    {
        GUI.Box(new Rect(0, 0, 100, 20), "Score:" + Score);
    }

    //아이템에서 좀더 범용적인 처리가 가능하다.
    //private void OnTriggerEnter2D(Collider2D collision)
    //{
    //    //if(collision.gameObject.name == "cherry" ||
    //    //    collision.gameObject.name == "gem")
    //    if(collision.gameObject.tag == "Item")
    //    {
    //        Score++;
    //        Destroy(collision.gameObject);
    //    }
    //}
}
