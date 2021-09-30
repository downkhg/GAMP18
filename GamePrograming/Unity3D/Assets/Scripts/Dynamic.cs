using UnityEngine;

public class Dynamic : MonoBehaviour
{
    public float m_fSpeed;
    public float m_fJumpPower;
    public bool m_isJump;

    [SerializeField]
    string m_strTargetTag;

    public Cannon m_cCannon;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if(Input.GetKey(KeyCode.UpArrow))
            transform.Translate(Vector3.forward * m_fSpeed * Time.deltaTime);
        if (Input.GetKey(KeyCode.DownArrow))
            transform.Translate(Vector3.back * m_fSpeed * Time.deltaTime);
        if (Input.GetKey(KeyCode.RightArrow))
            transform.Rotate(Vector3.up);
        if (Input.GetKey(KeyCode.LeftArrow))
            transform.Rotate(Vector3.down);

        if(Input.GetKeyDown(KeyCode.Space))
        {
            if (m_isJump == false)
            {
                Rigidbody rigidbody = GetComponent<Rigidbody>();
                rigidbody.AddForce(Vector3.up * m_fJumpPower);
                m_isJump = true;
            }
        }

        if (Input.GetKeyDown(KeyCode.X))
            m_cCannon.Shot(m_strTargetTag);
    }

    private void OnCollisionEnter(Collision collision)
    {
        m_isJump = false;
    }
}
