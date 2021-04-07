using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Gun : MonoBehaviour
{
    public GameObject prefabBullet;
    public float ShotPower;
    public float Dist;
   

    void Shot()
    {
        GameObject objBullet = Instantiate(prefabBullet);
        objBullet.transform.position = this.transform.position;
        Rigidbody2D rigidbody = objBullet.GetComponent<Rigidbody2D>();
        rigidbody.AddForce(Vector3.right * ShotPower);
        Bullet bullet = objBullet.GetComponent<Bullet>();
        bullet.Dist = Dist;
        //Destroy(objBullet, 1);
    }

    // Start is called before the first frame update
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Z))
            Shot();
    }
}
