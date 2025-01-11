# MapReduce Framework in C++
This project involves implementing a basic **MapReduce framework** using core **operating system concepts**. The framework simulates a distributed data processing system on a single machine, utilizing parallel processing to handle large-scale data efficiently. The project showcases the essential phases of the MapReduce paradigm: **Map**, **Shuffle**, and **Reduce**.

## **Project Description**
The objective of this project is to gain a deeper understanding of **concurrent computing** and **synchronization** by simulating a MapReduce algorithm. The project focuses on breaking down a large computational task into smaller, independent subtasks that can be processed in parallel. This is a key concept in distributed systems and parallel computing.

The project is structured into three phases:

1. **Map Phase**
2. **Shuffle Phase**
3. **Reduce Phase**

## **Phases of the MapReduce Framework**

### **1. Map Phase**
The **Map Phase** processes input data in parallel and outputs a collection of intermediate **key-value pairs**. The input data is divided into smaller chunks, with each chunk processed independently by a map function.

### **2. Shuffle Phase**
The **Shuffle Phase** occurs between the **Map** and **Reduce** phases. It groups the intermediate key-value pairs by key, ensuring that all occurrences of a particular key are collected together. This step is crucial for efficient processing in the **Reduce Phase**.

### **3. Reduce Phase**
The **Reduce Phase** processes the grouped key-value pairs to perform aggregation or computation. Each unique key from the **Map Phase** is sent to a reduce function, which aggregates the associated values to produce the final output.

---

## **Example Workflow**
### **Input:**
```
pizza burger pasta pasta pizza
```

### **Map Phase Output:**
```
("pizza", 1), ("burger", 1), ("pasta", 1), ("pasta", 1), ("pizza", 1)
```

### **Shuffle Phase Output:**
```
("pizza", [1, 1]), ("burger", [1]), ("pasta", [1, 1])
```

### **Reduce Phase Output:**
```
("pizza", 2), ("burger", 1), ("pasta", 2)
```

---

## **Key Concepts Utilized**
- **Multithreading:**
  - The project uses multiple threads to process chunks of input data in parallel during the **Map Phase**.
- **Synchronization:**
  - Proper synchronization mechanisms are implemented to manage shared resources and avoid race conditions.
- **Memory Management:**
  - Efficient memory allocation and cleanup are performed to ensure optimal resource usage.

## **How to Run the Project**
### **Step 1:** Clone the Repository
```bash
git clone https://github.com/ZainUlWahab/Map-Reduce-Framework.git
cd Map-Reduce-Framework
```

### **Step 2:** Then we will write "make" to run our "makefile" to make our .o files.
```bash
make
```

### **Step 3:** Then we will write "./main" to run our script.
```bash
./main
```
### **Step 4:** Optional: 
    To change test cases, change "test1.txt" to "test2.txt" or "test3.txt" in main.cpp on line 26.

## **Features Implemented**
- **Parallel Processing:** Input data is processed in parallel using multiple threads.
- **Key-Value Pair Management:** Intermediate key-value pairs are efficiently managed and grouped.
- **Aggregation:** The reduce function aggregates values associated with each key to produce the final output.

## **Technologies Used**
- **C++**
- **Multithreading (pthreads)**
- **File I/O**
- **Synchronization Mechanisms**

## **Memory Management**
Memory cleanup is performed to ensure that no memory leaks occur during execution. The project implements RAII (Resource Acquisition Is Initialization) to manage resources effectively.

## **Future Enhancements**
- Implement dynamic load balancing to improve efficiency.
- Extend the framework to support distributed processing across multiple machines.
- Add fault-tolerance mechanisms.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

## **Contributions**
Contributions are welcome! Feel free to open issues or submit pull requests for improvements.

## **Contact**
For any inquiries or feedback, please contact me at:
- **Email:** ulwahabzain@gmail.com

Thank you.
