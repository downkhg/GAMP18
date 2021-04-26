/*##################################
UnityObject
Filename: UnityObject.cs
Writer: Hong Guy Kim (downkhg@gmail.com)
Comment: This class is an object that visualizes game objects in the Unity editor.
###################################*/
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using UnityEngine;
using UnityEditor;

namespace HierachyWindow
{
    public class UnityObject
    {
        RectEx m_rectWindow;
        string m_strName;
        int m_nId;
        Color m_strColor;
        GameObject m_GameObeject;

        bool m_isShowComponent = false;

        public string Name { get { return m_strName; } }
        public int ID { get { return m_nId; } }
        public Color Color { get { return m_strColor; } }
        public RectEx RectWindow { get { return m_rectWindow; } set { m_rectWindow = value; } }
        public GameObject GameObject { get { return m_GameObeject; } }

        public List<UnityComponet> m_compoents;

        public override string ToString()
        {
            return string.Format("\n{0}:{1}\nTag:{2}\nLayer:{3}\nRect({4})", m_nId, m_strName, m_GameObeject.tag, LayerMask.LayerToName(m_GameObeject.layer), m_rectWindow.ToString());
        }

        public UnityObject(int id, GameObject obj)
        {
            m_GameObeject = obj;
            m_nId = id + 1;
            Vector2 vSize = HierachyWindowSetting.vObjectSize;
            //m_rectWindow = new RectEx(id * vSize.x, id * vSize.y, vSize.x, vSize.y);
            m_rectWindow = new RectEx(0, 0, vSize.x, vSize.y);
            m_strColor = HierachyWindowSetting.ObjectColor;
            m_strName = obj.name;

            Debug.Log(m_strName);

            Component[] componets = obj.GetComponents<Component>();
            m_compoents = new List<UnityComponet>(componets.Length);
            for (int i = 0; i < componets.Length; i++)
            {
                UnityComponet unityComponet = new UnityComponet(m_nId, i, componets[i], this);
                m_compoents.Add(unityComponet);
            }
        }

        public UnityObject(int id, int idx, Component component, UnityObject parent = null)
        {
            m_nId = id * 100 + idx;
            Vector2 vMagin = HierachyWindowSetting.vMargin;
            Vector2 vSize = HierachyWindowSetting.vComponentSize;
            RectEx rectParent = parent.RectWindow;
            m_rectWindow = new RectEx(rectParent.x + vMagin.x + rectParent.width, rectParent.y + idx * (vMagin.y + vSize.y), vSize.x, vSize.y);
            m_strColor = HierachyWindowSetting.ComponentColor;

            string[] strTypeParsers = component.GetType().ToString().Split(new char[] { '.' });
            m_strName = strTypeParsers[strTypeParsers.Length - 1];

            Debug.Log(m_strName);
        }

        public UnityObject(int id, string name, Rect rect, Color color, int capacity = 0)
        {
            m_compoents = new List<UnityComponet>(capacity);
            m_rectWindow = new RectEx(rect);
            m_strName = name;
            m_nId = id;
            m_strColor = color;
        }

        public UnityObject(int id, string name, float x, float y, float width, float height, Color color, int capacity = 0)
        {
            m_compoents = new List<UnityComponet>(capacity);
            m_rectWindow = new RectEx(x, y, width, height);
            m_strName = name;
            m_nId = id;
            m_strColor = color;
        }


        public void AddComponent(UnityComponet rectWindow)
        {
            m_compoents.Add(rectWindow);
        }
        public void RemoveComponent(UnityComponet rectWindow)
        {
            m_compoents.Remove(rectWindow);
        }

        public void DrawBeziers()
        {
            if (m_GameObeject.transform.parent != null)
            {
                GameObject objParent = m_GameObeject.transform.parent.transform.gameObject;
                UnityObject parent = HierachyEditorWindow.GetInstance().GetUnityObject(objParent);
                Vector3 vStartPos = parent.RectWindow.Rect.center;
                Vector3 vEndPos = this.RectWindow.Rect.center;
                Vector3 vCenterPos = new Vector3(vStartPos.x, vEndPos.y, 0);

                Handles.DrawBezier(vStartPos, vEndPos, vCenterPos, vCenterPos, HierachyWindowSetting.BezierParentColor, null, 5f);

            }

            if (m_compoents != null && m_isShowComponent)
            {
                for (int i = 0; i < m_compoents.Count; i++)
                {
                    Handles.DrawBezier(m_rectWindow.center, m_compoents[i].RectWindow.center, m_rectWindow.center, m_compoents[i].RectWindow.center, HierachyWindowSetting.BezierParentColor, null, 5f);
                }
            }
        }

        public void DrawWindows()
        {
            GUI.color = m_strColor;
            string strBox = ToString();
            m_rectWindow.Rect = GUI.Window(m_nId, m_rectWindow.Rect, WindowFunction, strBox);


            if (m_compoents != null && m_isShowComponent)
            {
                for (int i = 0; i < m_compoents.Count; i++)
                {
                    m_compoents[i].DrawWindows();
                }
            }
        }

        void WindowFunction(int windowID)
        {
            //Debug.Log("WindowFunction" + windowID);

            Rect rectButton = RectWindow.Rect;
            float rectTitleHeight = 20;
            rectButton.height = rectTitleHeight;
            rectButton.x = 0;
            rectButton.y = 0;

            for (int i = 0; i < m_compoents.Count; i++)
            {
                m_compoents[i].Update(i);
            }
            GUI.color = HierachyWindowSetting.TitleObjectColor;
            if (GUI.Button(rectButton, m_strName))
            {
                if (m_isShowComponent)
                    m_isShowComponent = false;
                else
                    m_isShowComponent = true;
                Debug.Log("WindowFunction" + windowID);
            }
            GUI.DragWindow();
        }
    }
}
