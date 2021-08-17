using System;
using System.Collections.Generic;
using System.Threading;
using System.Threading.Tasks;

namespace ThreadTaskAsync
{
    class TestThread
    {
        public int nId;

        public TestThread(int id)
        {
            nId = id;
        }

        public void ThreadCallBack()
        {
            for (int i = 0; i < 9999; i++)
            {
                //Console.WriteLine(nId+":ThreadCallBack:" + i);
            }
        }
    }

    class Program
    {
        //각 쓰레드 풀을 2000개씩 만들어 작동시키기고 끝날때까지 프로그램 지연하기
        static int nFullCount = 2000;
        //쓰레드가 많아지면 느려진다.
        static void ThreadTestMain()
        {
            List<Thread> listThread = new List<Thread>();
            float fTime =  DateTime.Now.Millisecond;
            for (int i = 0; i < nFullCount; i++)
            {
                TestThread testThread = new TestThread(i);
                ThreadStart threadStart = new ThreadStart(testThread.ThreadCallBack);
                Thread thread = new Thread(threadStart);
                listThread.Add(thread);
                thread.Start();
            };

            for (int i = 0; i < nFullCount; i++)
            {
                listThread[i].Join();
            };

            Console.WriteLine("ThreadDelayTime:{0}", DateTime.Now.Millisecond - fTime);
        }
        //내부에서 스레드를 관리하므로 쓰레드에비해 빠르게 처리된다.
        static void TaskTestMain()
        {
            List<Task> listTask = new List<Task>();
            float fTime = DateTime.Now.Millisecond;
            for (int i = 0; i < nFullCount; i++)
            {
                TestThread testThread = new TestThread(i);
                Task thread = new Task(testThread.ThreadCallBack);
                listTask.Add(thread);
                thread.Start();
            };

            for (int i = 0; i < nFullCount; i++)
            {
                listTask[i].Wait();
            };
            Console.WriteLine("TaskDelayTime:{0}",  DateTime.Now.Millisecond - fTime);
        }

        static void Main(string[] args)
        {
            //ThreadTestMain();
            TaskTestMain();
        }
    }
}
