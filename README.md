# Project: Plagiarism Checker & File Management System

## Installation

Prerequisites:
- `MySQL`
- `Python`
- `Bit of patience`

### Database
Note that for now you should run DDL `db/user.sql` manually. 

### Backend
First, run the backend the root folder:

`$ make`

Then, run the server:

`$ ./backend/server

### Protocol

#### Request
`<route> <arg1> <arg2> ... <argn>`

#### Response
`<route> <status> <payload?>`

### Frontend

Open QT creator and load `frontend-qt` folder.

There you can build the frontend. Run frontend only after setting up the server.

## Problem Statement
Plagiarism is a representation of another author’s languages or ideas as one’s own original work. It was an acute problem from ancient times, and with advent of informational revolution, it has become much more important in both academic and intellectual world. 
According to survey by The Center for Academic Integrity around 80% of undergraduates in USA have cheated at least once. Such alarming numbers are a result of missed plagiarism cases which could be detected by using plagiarism or content similarity detection algorithm.
Therefore, one’s job is to develop content similarity detection system which composes several plagiarism detection algorithms.

## Abstract
In this proposal, we present the rough project plan on the development of the information system (IS) with the main purpose of plagiarism detection. We present how the conceptual architecture will utilize several inteprocess communication topics, specifically socket communcation. Our application is based on client-server architecture, with the client based as a Web application and a server that runs on C. 

## Project Overview
Plagiarism detection system consists of several connected components. First, we need analyzer model, collection of algorithms that analyses a document and outputs the similarity percentage. Next, we need to make a client app that facilitates users to use our system in a comfortable way. Last but not least, we need to develop application server that serves as an intermediary between the client and the business logic. So, to recap:
1. Core model with business logic
2. Client application
3. Server application

A complete view of these components is illustrated in Figure 1.

![alt text](https://user-images.githubusercontent.com/26520665/145014825-5881b1d1-6477-4118-a82a-de2037867734.png)

As you can see, our application will be web-based. Implementations of each component are given below:
1. **Client Side.** React. The core library is React JS library, and the user interface will be marked up using HTML and Bootstrap.
2. **Server Side.**
We will write our own server that serves as an application server between our client and business logic. It will make use of interprocess communication, in particular, socket network programming.
3. **Core Business Model.** The utility algorithms that are arranged in a pipe. These are algorithms that are written in C, thus providing better performance and speed. They are accessed at runtime by the server, so the communcation is done via sockets as well.
4. **Database Model.** Our DBMS used by our server to store the data of the most frequent used combinations of words that are plagiarized often for faster access. It acts like a cache for our IS. We need file management access which will be done using built-in C functions.

## Core Business Model 
Here we present 4 parameters that drive our IS. Most of the plagiarism checking systems follow such parameters to define the system requirements for their software.

Parameter           |	Description
------------------- | --------------------------------------------------------------------------
Initial corpus      | Our main scope of search. 
Number of documents | How many documents a system can check simultaneously
Check level         | At what level of semantics we check (e.g, phrases, sentences, paragraphs)
Algorithms used     | Algorithms used to develop system

In our information system (IS) we define the parameters as following:
1. Initial corpus. We will use search engine Google as our core corpus, as well as other users works.
2. Number of documents. Our IS will process two documents at a time.
3. Check level. We mainly focus on phrases and sentences (refer to Figure 2)
4. Algorithms used. We will combine many algorithms in our inventory and develop a pipe of algorithms for each step of analysis.

![alt text](https://user-images.githubusercontent.com/26520665/145015930-d20efcd9-cfeb-46d0-be0b-0907e38e9acc.png)

Given these parameters, our approach will vary as we progress and get to know how plagiarism checker system operate. For example, for starters, we can start with substring matching in the document. Such approach may suffice at the level of copying and paste, but for paraphrasing other solutions should be adopted.
