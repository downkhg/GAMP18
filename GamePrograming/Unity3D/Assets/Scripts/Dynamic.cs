using UnityEngine;

public class Dynamic : MonoBehaviour
{
    public float m_fSpeed;
    public float m_fJumpPower;
    public bool m_isJump;

    public Cannon m_cCannon;

    public void Jump(Rigidbody rigidbody)
    {
        if (m_isJump == false)
        {
            rigidbody.AddForce(Vector3.up * m_fJumpPower);
            m_isJump = true;
        }
    }

    public void Jump(SimpleRigidBody rigidbody)
    {
        //if (m_isJump == false)
        {
            rigidbody.AddForce(Vector3.up,m_fJumpPower);
            m_isJump = true;
        }
    }

    public float Move(Transform tr, Vector3 dir)
    {
        float fMove = m_fSpeed * Time.deltaTime;
        tr.Translate(dir * m_fSpeed * Time.deltaTime);
        return fMove;
    }

    public void Shot(string TargetTag)
    {
        m_cCannon.Shot(TargetTag);
    }
}
