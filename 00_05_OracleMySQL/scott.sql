prompt PL/SQL Developer import file
prompt Created on 2017Äê12ÔÂ9ÈÕ by liangboyan
set feedback off
set define off
prompt Dropping BONUS...
drop table BONUS cascade constraints;
prompt Dropping DEPT...
drop table DEPT cascade constraints;
prompt Dropping EMP...
drop table EMP cascade constraints;
prompt Dropping SALGRADE...
drop table SALGRADE cascade constraints;
prompt Creating BONUS...
create table BONUS
(
  ename VARCHAR2(10),
  job   VARCHAR2(9),
  sal   NUMBER,
  comm  NUMBER
)
tablespace USERS
  pctfree 10
  initrans 1
  maxtrans 255;

prompt Creating DEPT...
create table DEPT
(
  deptno NUMBER(2) not null,
  dname  VARCHAR2(14),
  loc    VARCHAR2(13)
)
tablespace USERS
  pctfree 10
  initrans 1
  maxtrans 255
  storage
  (
    initial 64K
    next 1M
    minextents 1
    maxextents unlimited
  );
alter table DEPT
  add constraint PK_DEPT primary key (DEPTNO)
  using index 
  tablespace USERS
  pctfree 10
  initrans 2
  maxtrans 255
  storage
  (
    initial 64K
    next 1M
    minextents 1
    maxextents unlimited
  );

prompt Creating EMP...
create table EMP
(
  empno    NUMBER(4) not null,
  ename    VARCHAR2(10),
  job      VARCHAR2(9),
  mgr      NUMBER(4),
  hiredate DATE,
  sal      NUMBER(7,2),
  comm     NUMBER(7,2),
  deptno   NUMBER(2)
)
tablespace USERS
  pctfree 10
  initrans 1
  maxtrans 255
  storage
  (
    initial 64K
    next 1M
    minextents 1
    maxextents unlimited
  );
alter table EMP
  add constraint PK_EMP primary key (EMPNO)
  using index 
  tablespace USERS
  pctfree 10
  initrans 2
  maxtrans 255
  storage
  (
    initial 64K
    next 1M
    minextents 1
    maxextents unlimited
  );
alter table EMP
  add constraint FK_DEPTNO foreign key (DEPTNO)
  references DEPT (DEPTNO);

prompt Creating SALGRADE...
create table SALGRADE
(
  grade NUMBER,
  losal NUMBER,
  hisal NUMBER
)
tablespace USERS
  pctfree 10
  initrans 1
  maxtrans 255
  storage
  (
    initial 64K
    next 1M
    minextents 1
    maxextents unlimited
  );

prompt Disabling triggers for BONUS...
alter table BONUS disable all triggers;
prompt Disabling triggers for DEPT...
alter table DEPT disable all triggers;
prompt Disabling triggers for EMP...
alter table EMP disable all triggers;
prompt Disabling triggers for SALGRADE...
alter table SALGRADE disable all triggers;
prompt Disabling foreign key constraints for EMP...
alter table EMP disable constraint FK_DEPTNO;
prompt Loading BONUS...
prompt Table is empty
prompt Loading DEPT...
insert into DEPT (deptno, dname, loc)
values (10, 'ACCOUNTING', 'NEW YORK');
insert into DEPT (deptno, dname, loc)
values (20, 'RESEARCH', 'DALLAS');
insert into DEPT (deptno, dname, loc)
values (30, 'SALES', 'CHICAGO');
insert into DEPT (deptno, dname, loc)
values (40, 'OPERATIONS', 'BOSTON');
commit;
prompt 4 records loaded
prompt Loading EMP...
insert into EMP (empno, ename, job, mgr, hiredate, sal, comm, deptno)
values (7369, 'SMITH', 'CLERK', 7902, to_date('17-12-1980', 'dd-mm-yyyy'), 800, null, 20);
insert into EMP (empno, ename, job, mgr, hiredate, sal, comm, deptno)
values (7499, 'ALLEN', 'SALESMAN', 7698, to_date('20-02-1981', 'dd-mm-yyyy'), 1600, 300, 30);
insert into EMP (empno, ename, job, mgr, hiredate, sal, comm, deptno)
values (7521, 'WARD', 'SALESMAN', 7698, to_date('22-02-1981', 'dd-mm-yyyy'), 1250, 500, 30);
insert into EMP (empno, ename, job, mgr, hiredate, sal, comm, deptno)
values (7566, 'JONES', 'MANAGER', 7839, to_date('02-04-1981', 'dd-mm-yyyy'), 2975, null, 20);
insert into EMP (empno, ename, job, mgr, hiredate, sal, comm, deptno)
values (7654, 'MARTIN', 'SALESMAN', 7698, to_date('28-09-1981', 'dd-mm-yyyy'), 1250, 1400, 30);
insert into EMP (empno, ename, job, mgr, hiredate, sal, comm, deptno)
values (7698, 'BLAKE', 'MANAGER', 7839, to_date('01-05-1981', 'dd-mm-yyyy'), 2850, null, 30);
insert into EMP (empno, ename, job, mgr, hiredate, sal, comm, deptno)
values (7782, 'CLARK', 'MANAGER', 7839, to_date('09-06-1981', 'dd-mm-yyyy'), 2450, null, 10);
insert into EMP (empno, ename, job, mgr, hiredate, sal, comm, deptno)
values (7788, 'SCOTT', 'ANALYST', 7566, to_date('19-04-1987', 'dd-mm-yyyy'), 3000, null, 20);
insert into EMP (empno, ename, job, mgr, hiredate, sal, comm, deptno)
values (7839, 'KING', 'PRESIDENT', null, to_date('17-11-1981', 'dd-mm-yyyy'), 5000, null, 10);
insert into EMP (empno, ename, job, mgr, hiredate, sal, comm, deptno)
values (7844, 'TURNER', 'SALESMAN', 7698, to_date('08-09-1981', 'dd-mm-yyyy'), 1500, 0, 30);
insert into EMP (empno, ename, job, mgr, hiredate, sal, comm, deptno)
values (7876, 'ADAMS', 'CLERK', 7788, to_date('23-05-1987', 'dd-mm-yyyy'), 1100, null, 20);
insert into EMP (empno, ename, job, mgr, hiredate, sal, comm, deptno)
values (7900, 'JAMES', 'CLERK', 7698, to_date('03-12-1981', 'dd-mm-yyyy'), 950, null, 30);
insert into EMP (empno, ename, job, mgr, hiredate, sal, comm, deptno)
values (7902, 'FORD', 'ANALYST', 7566, to_date('03-12-1981', 'dd-mm-yyyy'), 3000, null, 20);
insert into EMP (empno, ename, job, mgr, hiredate, sal, comm, deptno)
values (7934, 'MILLER', 'CLERK', 7782, to_date('23-01-1982', 'dd-mm-yyyy'), 1300, null, 10);
commit;
prompt 14 records loaded
prompt Loading SALGRADE...
insert into SALGRADE (grade, losal, hisal)
values (1, 700, 1200);
insert into SALGRADE (grade, losal, hisal)
values (2, 1201, 1400);
insert into SALGRADE (grade, losal, hisal)
values (3, 1401, 2000);
insert into SALGRADE (grade, losal, hisal)
values (4, 2001, 3000);
insert into SALGRADE (grade, losal, hisal)
values (5, 3001, 9999);
commit;
prompt 5 records loaded
prompt Enabling foreign key constraints for EMP...
alter table EMP enable constraint FK_DEPTNO;
prompt Enabling triggers for BONUS...
alter table BONUS enable all triggers;
prompt Enabling triggers for DEPT...
alter table DEPT enable all triggers;
prompt Enabling triggers for EMP...
alter table EMP enable all triggers;
prompt Enabling triggers for SALGRADE...
alter table SALGRADE enable all triggers;
set feedback on
set define on
prompt Done.
