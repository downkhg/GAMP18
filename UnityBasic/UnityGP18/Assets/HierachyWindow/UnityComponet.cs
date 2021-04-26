/*##################################
UnityComponet
Filename: UnityComponet.cs
Writer: Hong Guy Kim (downkhg@gmail.com)
Comment: This class is an object that visualizes Componets in the Game Object.
###################################*/
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using UnityEngine;

namespace HierachyWindow
{
    public class UnityComponet
    {
        RectEx m_rectWindow;
        string m_strName;
        int m_nId;

        Color m_strColor;
        UnityObject m_unitObjectParent;
        Component m_Component;

        public string Name { get { return m_strName; } }
        public int ID { get { return m_nId; } }
        public Color Color { get { return m_strColor; } }
        public RectEx RectWindow { get { return m_rectWindow; } set { m_rectWindow = value; } }
        public Component Component { get { return m_Component; } }

        public override string ToString()
        {
            return string.Format("{0}:{1}\nRect{2}", m_nId, m_strName, m_rectWindow.ToString());
        }

        public UnityComponet(int id, int idx, Component component, UnityObject parent = null)
        {
            m_unitObjectParent = parent;
            m_nId = id * 100 + idx;
            Vector2 vMagin = new Vector2(50, 20);
            Vector2 vSize = new Vector2(150, 60);
            RectEx rectParent = parent.RectWindow;
            m_rectWindow = new RectEx(rectParent.x + vMagin.x + rectParent.width, rectParent.y + idx * (vMagin.y + vSize.y), vSize.x, vSize.y);
            m_strColor = Color.gray;

            string[] strTypeParsers = component.GetType().ToString().Split(new char[] { '.' });
            m_strName = strTypeParsers[strTypeParsers.Length - 1];

            Debug.Log(m_strName);
        }

        public void Update(int idx)
        {
            RectEx rectParent = m_unitObjectParent.RectWindow;
            Vector2 vMagin = new Vector2(50, 20);
            Vector2 vSize = new Vector2(m_rectWindow.width, m_rectWindow.height);
            m_rectWindow = new RectEx(rectParent.x + vMagin.x + rectParent.width, rectParent.y + idx * (vMagin.y + vSize.y), vSize.x, vSize.y);
        }

        public void DrawWindows()
        {
            GUI.color = m_strColor;
            //string strRect = m_rectWindow.ToString();
            //string strBox = m_strName;// + "\n";// + strRect;
            //string strBox = string.Format("{0}\n{1}",m_strName,m_rectWindow.ToString());
            string strBox = ToString();
            m_rectWindow.Rect = GUI.Window(m_nId, m_rectWindow.Rect, WindowFunction, strBox);
        }

        void WindowFunction(int windowID)
        {
            //Debug.Log("WindowFunction" + windowID);

            Rect rectButton = RectWindow.Rect;
            float rectTitleHeight = 20;
            rectButton.height = rectTitleHeight;
            rectButton.x = 0;
            rectButton.y = 0;
            GUI.color = HierachyWindowSetting.TitleComponentColor;
            if (GUI.Button(rectButton, m_strName))
            {
                Debug.Log("WindowFunction" + windowID);
            }
            GUI.DragWindow();
        }
    }

}
