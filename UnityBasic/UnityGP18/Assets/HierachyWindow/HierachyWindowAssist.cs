/*##################################
HierachyWindowAssist
Filename: HierachyWindowAssist.cs
Writer: Hong Guy Kim (downkhg@gmail.com)
Comment: In this file Class and Struct are the classes that set up or assist in the "Hierachy Window".
###################################*/
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using UnityEngine;

namespace HierachyWindow
{
    static class HierachyWindowSetting
    {
        public static GameObject[] GetChiledObject(GameObject obj)
        {
            return GameObject.FindObjectsOfType<GameObject>();
        }
        public static Component[] GetComponents(GameObject obj)
        {
            return obj.GetComponents<Component>();
        }


        public static Vector2 vMargin = new Vector2(50, 20);
        public static Vector2 vObjectSize = new Vector2(150, 100);
        public static Vector2 vComponentSize = new Vector2(150, 60);
        public static Color ObjectColor = new Color(0.7f, 0.7f, 0.7f);
        public static Color ComponentColor = new Color();
        public static Color TitleObjectColor = Color.green;
        public static Color TitleComponentColor = Color.cyan;
        public static Color BezierComponentColor = Color.red;
        public static Color BezierParentColor = Color.blue;
    }

    public struct RectEx
    {
        Rect Rectangle { get; set; }

        public RectEx(Rect rect)
        {
            Rectangle = rect;
        }
        public RectEx(float x, float y, float width, float height)
        {
            Rectangle = new Rect(x, y, width, height);
        }

        public float x { get { return Rectangle.x; } }
        public float y { get { return Rectangle.y; } }
        public float width { get { return Rectangle.width; } }
        public float height { get { return Rectangle.height; } }

        public Vector2 topLeft { get { return new Vector2(Rectangle.x, Rectangle.y); } }
        public Vector2 topRight { get { return new Vector2(Rectangle.x, Rectangle.y + Rectangle.width); } }
        public Vector2 bottomLeft { get { return new Vector2(Rectangle.x + Rectangle.width, Rectangle.y); } }
        public Vector2 bottomRight { get { return new Vector2(Rectangle.x + Rectangle.width, Rectangle.y + Rectangle.width); } }
        public Vector2 center { get { return Rectangle.center; } }
        public Vector2 centerRight { get { return new Vector2(Rectangle.x + Rectangle.width, Rectangle.center.y); } }
        public Vector2 centerLeft { get { return new Vector2(Rectangle.x, Rectangle.center.y); } }
        public Vector2 centerTop { get { return new Vector2(Rectangle.center.x, Rectangle.y); } }
        public Vector2 centerBottom { get { return new Vector2(Rectangle.center.x, Rectangle.y + Rectangle.height); } }
        public float xMax { get { return Rectangle.xMax; } }
        public float xMin { get { return Rectangle.xMin; } }

        public Rect Rect { get { return Rectangle; } set { Rectangle = value; } }

        override public string ToString()
        {
            return string.Format("{0},{1},{2},{3}", Rectangle.x, Rectangle.y, Rectangle.width, Rectangle.height);
        }
    }
}
