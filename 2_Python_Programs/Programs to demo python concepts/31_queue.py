#python queue data structure
import queue;
q1 = queue.Queue();
q1.put(10);
print(q1.get());
q1.put(20);
q1.put(30);
q1.put(40);
print(q1.get());
print(q1.get());
print(q1.get());