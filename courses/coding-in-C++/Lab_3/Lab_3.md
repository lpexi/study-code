# Lab 2: From C to C++

This lab focuses on getting started with C++ especially for programmers familiar with C.

All the following sections of this lab are based on the following levels of dificulty:

🟢 __Simple__: A simple coding task that usually guides you step by step through the process and focuses on learning the basics. It should not take more than 15min to finish it.

🟡 __Moderate__: A coding task that usually states a moderate problem to test your understanding and transfer skills from syntax to real-world applications. These tasks can be solved in about 30mins depending on your knowledge.

🔴 __Complex__: Quite a difficult or lengthy coding task that requires you to use the acquired knowledge of the previous tasks in a broader context or project. Such tasks might take up to a few hours to solve them.

## 🟡 Section I: UML Modeling – Online Learning Platform

In this section you will model a simplified __Online Learning Platform__ and focus on identifying and designing __relationships__ between classes.

You will practice the following concepts:

- UML class diagrams  
- identifying __composition vs aggregation__  
- modeling multiplicities and associations  
- transferring UML into C++ code  

---

### 🧩 Task Description

You are asked to design a simplified __Online Learning Platform__ (similar to Moodle).

The platform manages courses, learning content, and users.

---

### 📘 Requirements

- The platform offers multiple __courses__.
  - The number of courses is technically limited to __100__

- A __course__ represents a learning unit:
  - it should have a title and a description  
  - it should allow adding or in general organizing its learning material

- A course is structured into smaller parts called __lessons__:
  - each lesson can contain different types of __content__  
  - content could be, for example, text, video, or quizzes  

- Users can participate in courses:
  - a __user__ should have identifying information  
  - users should be able to enroll or leave in courses  
  - users need to be registered __at least on one platform__ (e.g. Moodle RV, FN, etc.)

---

### Task Part 1 – UML Diagram

Create a UML class diagram in draw.io that:

1. Identifies all relevant classes based on the description  
2. Defines:
   - attributes with visibility and types  
   - methods (at least one meaningful method per class)

3. Models relationships:
   - clearly distinguish between:
     - __composition__
     - __aggregation__
     - __association__

4. Includes:
   - multiplicities (e.g. 1, 0..*, etc.)
   - roles or attributes connecting the classes

You must decide yourself:

- which elements should be modeled as __classes__
- which properties should be __attributes__
- which actions should be __methods__

and especially:

- which relationships are __compositions__
- which are __aggregations__
- which are simple __associations__

---

### Task Part 2 – Justification

Answer the following:

1. Which relationships did you model as __composition__ and why?  
2. Which relationships did you model as __aggregation__ and why?  
3. Which design decisions were not obvious and could be modeled differently?  

👉 There is not always a single correct answer — your reasoning is essential.

---

### Task Part 3 – C++ Implementation

Transfer your UML model into C++ code.

---

- Implement the classes you identified  
- Use appropriate access modifiers (`private`, `public`)  
- Represent relationships using:
  - direct members (for strong ownership)
  - pointers or references (for weaker relationships)

- In main, create objects of your classes
- Simulate interaction (e.g. enrolling, accessing content)  
- Call at least one method from each class  
