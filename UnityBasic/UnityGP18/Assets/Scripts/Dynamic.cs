﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Dynamic : MonoBehaviour
{
    public float JumpPower;
    public bool isJump = false;
    public bool isRadder = false;
    public float Speed = 1;
    public int Score;

    public Gun gun;

    public Vector3 dir = Vector3.right;

    // Update is called once per frame
    void Update()
    {
        //transform.position += Vector3.right * Time.deltaTime;

        if (Input.GetKeyDown(KeyCode.X))
            gun.Shot(dir,GetComponent<Player>());

        if (Input.GetKey(KeyCode.RightArrow))
        {
            //transform.Rotate(Vector3.up * 180);
            //transform.rotation = Quaternion.Euler(0, 0, 0);
            dir = Vector3.right;
            transform.localScale = new Vector3(1, 1, 1);
            transform.position += Vector3.right * Speed * Time.deltaTime;
        }
        //왼쪽으로 이동하기 추가해보기.
        if (Input.GetKey(KeyCode.LeftArrow))
        {
            //transform.rotation = Quaternion.Euler(0, 180, 0);
            dir = Vector3.left;
            transform.localScale = new Vector3(-1, 1, 1);
            transform.position += Vector3.left * Speed * Time.deltaTime;
        }

        if (Input.GetKeyDown(KeyCode.Space))
        {
            if (isJump == false)
            {
                Rigidbody2D rigidbody2D = GetComponent<Rigidbody2D>();
                rigidbody2D.velocity = Vector2.zero;
                rigidbody2D.AddForce(Vector3.up * JumpPower);
                isJump = false;
            }
        }

        if(isRadder == true)
        {
            if (Input.GetKey(KeyCode.UpArrow))
                transform.position += Vector3.up * Time.deltaTime;
            //왼쪽으로 이동하기 추가해보기.
            if (Input.GetKey(KeyCode.DownArrow))
                transform.position += Vector3.down * Time.deltaTime;
        }

        
    }

    private void FixedUpdate()
    {
        SuperMode superMode = GetComponent<SuperMode>();
        if (superMode !=null && superMode.isOn) return;

        Vector3 vPos = this.transform.position;
        int nLayer = LayerMask.NameToLayer("Monster");

        CircleCollider2D circleCollider = GetComponent<CircleCollider2D>();
        vPos += new Vector3(circleCollider.offset.x, circleCollider.offset.y, 0);

        Collider2D collider = Physics2D.OverlapCircle(vPos, circleCollider.radius, 1 << nLayer);

        if(collider)
        {
            Player monster = collider.gameObject.GetComponent<Player>();
            Player player = this.gameObject.GetComponent<Player>();

            monster.Attack(player);
            superMode.Active();

            GameManager.GetInstance().spriteKillMounster =
                  monster.GetComponent<SpriteRenderer>().sprite;
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

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.gameObject.tag == "Radder")
        {
            isRadder = true;
            GetComponent<Rigidbody2D>().gravityScale = 0;
            GetComponent<Rigidbody2D>().velocity = Vector2.zero;
        }

        Debug.Log("OnTriggerEnter2D:" + collision.gameObject.name);
    }

    private void OnTriggerExit2D(Collider2D collision)
    {
        if (collision.gameObject.tag == "Radder")
        {
            isRadder = false;
            GetComponent<Rigidbody2D>().gravityScale = 1;
            GetComponent<Rigidbody2D>().velocity = Vector2.zero;
        }

        Debug.Log("OnTriggerExit2D:" + collision.gameObject.name);
    }

    private void OnTriggerStay2D(Collider2D collision)
    {
        if (collision.gameObject.name == "house")
        {
            if (Input.GetKeyDown(KeyCode.Z))
                GameManager.GetInstance().EventSceneChange(3);
        }
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
