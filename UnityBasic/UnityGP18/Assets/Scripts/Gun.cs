using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Gun : MonoBehaviour
{
    public GameObject prefabBullet;
    public float ShotPower;
    public float Dist;
   
    public void Shot(Vector3 dir, Player player)
    {
        GameObject objBullet = Instantiate(prefabBullet);
        objBullet.transform.position = this.transform.position;
        Rigidbody2D rigidbody = objBullet.GetComponent<Rigidbody2D>();
        rigidbody.AddForce(dir * ShotPower);
        Bullet bullet = objBullet.GetComponent<Bullet>();
        bullet.Dist = Dist;
        bullet.master = player;
        //Destroy(objBullet, 1);
    }
}
