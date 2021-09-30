using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Cannon : MonoBehaviour
{
    public GameObject prefabBullet;
    public float m_fShotPower;

    public void Shot(string targetTag)
    {
        GameObject objBullet = Instantiate(prefabBullet) as GameObject;
        objBullet.transform.position = this.transform.position;
        Rigidbody rigidbody = objBullet.GetComponent<Rigidbody>();
        Bullet bullet = objBullet.GetComponent<Bullet>();
        bullet.TargetTag = targetTag;
        rigidbody.AddForce(transform.forward * m_fShotPower);
        Destroy(objBullet, 1);
    }
}
