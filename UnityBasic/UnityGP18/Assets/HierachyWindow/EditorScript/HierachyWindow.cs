/*##################################
HierachyEditorWindow
Filename: HierachyEditorWindow.cs
Writer: Hong Guy Kim (downkhg@gmail.com)
Comment: "Hierarchy Window" is "Editor Window".
          It has a "Hashtable" that can access information of each created node and game object, and is singletonized.
###################################*/
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;
using HierachyWindow;

public class HierachyEditorWindow : EditorWindow
{
    List<UnityObject> m_UnityObjects;
    Hashtable m_hashObjects;
    Hashtable m_hashUnityObjects;

    static HierachyEditorWindow m_instance;

    static public HierachyEditorWindow GetInstance()
    {
        return m_instance;
    }

    public UnityObject GetUnityObject(GameObject obj)
    {
        return (UnityObject)m_hashObjects[obj.GetHashCode()];
    }

    public UnityObject GetUnityObjectId(int id)
    {
        return (UnityObject)m_hashUnityObjects[id];
    }

    [MenuItem("Window/Hierachy Window")]
    static void Init()
    {
        EditorWindow.GetWindow(typeof(HierachyEditorWindow));
    }

    public void GameObjectAllComponent(GameObject obj)
    {
        Component[] componets = obj.GetComponents<Component>();

        foreach (Component component in componets)
        {
            Debug.Log(component.GetType());
        }
    }

    private void OnEnable()
    {
        Debug.Log("OnEnable");

        m_instance = this;

        GameObject[] listObjects = GameObject.FindObjectsOfType<GameObject>();

        m_UnityObjects = new List<UnityObject>(listObjects.Length);
        m_hashObjects = new Hashtable(listObjects.Length);
        m_hashUnityObjects = new Hashtable(listObjects.Length);

        for (int i = 0; i < listObjects.Length; i++)
        {
            GameObject obj = listObjects[i];
            if (obj.activeSelf)
            {
                UnityObject unityObject = new UnityObject(i, obj);
                m_UnityObjects.Add(unityObject);
                m_hashObjects.Add(obj.GetHashCode(), unityObject);
                m_hashUnityObjects.Add(unityObject.ID, unityObject);
            }
        }
    }

    private void OnGUI()
    {
        Handles.BeginGUI();
        foreach (UnityObject unityObject in m_UnityObjects)
        {
            unityObject.DrawBeziers();
        }
        Handles.EndGUI();

        BeginWindows();

        foreach(UnityObject unityObject in m_UnityObjects)
        {
            unityObject.DrawWindows();
        }

        EndWindows();

    }
}
