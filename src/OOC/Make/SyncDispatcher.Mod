MODULE OOC:Make:SyncDispatcher;

IMPORT
  OOC:Make;


TYPE
  Job = POINTER TO JobDesc;
  JobDesc = RECORD
    next: Job;
    node: Make.Node;
    cmd: Make.BuildCmd;
  END;

TYPE
  Dispatcher* = POINTER TO DispatcherDesc;
  DispatcherDesc = RECORD
    (Make.JobDispatcherDesc)
    jobList: Job;
  END;


PROCEDURE Init (jd: Dispatcher);
  BEGIN
    Make.InitJobDispatcher (jd);
    jd. jobList := NIL;
  END Init;

PROCEDURE New* (): Dispatcher;
  VAR
    jd: Dispatcher;
  BEGIN
    NEW (jd);
    Init (jd);
    RETURN jd
  END New;

PROCEDURE NewJob (node: Make.Node; cmd: Make.BuildCmd): Job;
  VAR
    job: Job;
  BEGIN
    ASSERT (node # NIL);
    ASSERT (cmd # NIL);
    
    NEW (job);
    job. next := NIL;
    job. node := node;
    job. cmd := cmd;
    RETURN job
  END NewJob;

PROCEDURE (jd: Dispatcher) AddJob* (n: Make.Node; cmd: Make.BuildCmd);
  VAR
    job: Job;
    buildRes: Make.BuildResult;
  BEGIN
    job := NewJob (n, cmd);
    job. next := jd. jobList;
    jd. jobList := job;
    
(*    WHILE (jd. jobList # NIL) DO*)
    job := jd. jobList;
    jd. jobList := job. next;
    ASSERT (jd. jobList = NIL);
    buildRes := job. cmd. Build (job. node);
    job. node. BuildFinished (buildRes);
    ASSERT (jd. jobList = NIL);
(*    END*)
  END AddJob;

PROCEDURE (jd: Dispatcher) Reset*;
  BEGIN
    jd. Reset^;
    Init (jd)
  END Reset;

END OOC:Make:SyncDispatcher.
