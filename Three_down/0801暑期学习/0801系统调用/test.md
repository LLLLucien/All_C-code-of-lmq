# POSIX 系统调用 I/O 操作总结

> 来源文件：`io.c`

---

## 一、什么是 POSIX

**POSIX（Portable Operating System Interface）** 可移植操作系统接口，是 IEEE 定义的一套标准，旨在让不同 Unix 系统之间的程序具备可移植性。本文件通过 POSIX 接口演示底层 I/O 系统调用的使用。

---

## 二、相关头文件

| 头文件 | 作用 |
|--------|------|
| `<fcntl.h>` | **F**ile **C**o**n**trol Operations，文件控制操作（如 `open`） |
| `<unistd.h>` | Unix 标准系统调用（如 `read`、`write`、`close`） |
| `<stdio.h>` | 标准 I/O（`printf`） |
| `<string.h>` | 字符串操作（`memset`、`strlen`） |

---

## 三、文件描述符（File Descriptor）

文件描述符是一个非负整数，用于标识已打开的文件。每个进程启动时默认打开 3 个：

| 文件描述符 | 宏名 | 含义 |
|-----------|------|------|
| `0` | `stdin` | 标准输入（键盘） |
| `1` | `stdout` | 标准输出（屏幕） |
| `2` | `stderr` | 标准错误输出（屏幕） |

新打开的文件描述符一般从 `3` 开始分配。

---

## 四、核心系统调用

### 4.1 `open` —— 打开/创建文件

```c
int open(const char *pathname, int flags, mode_t mode);
```

- **参数说明**：
  - `pathname`：文件路径
  - `flags`：打开方式标志（如 `O_RDONLY`、`O_WRONLY`、`O_CREAT` 等），可用 `|` 组合
  - `mode`：创建文件时指定的权限（仅当 `O_CREAT` 存在时有效）
- **返回值**：成功返回文件描述符，失败返回 `-1`

**示例**：

```c
int fd = open("test4.txt", O_WRONLY | O_CREAT, 0660);
```

- `O_WRONLY`：只写方式打开
- `O_CREAT`：若文件不存在则创建
- `0660`（八进制）权限含义：

  | 数字 | 含义 |
  |------|------|
  | 0 | 八进制前缀 |
  | 6（用户） | rw-（读写） |
  | 6（用户组） | rw-（读写） |
  | 0（其他） | ---（无权限） |

---

### 4.2 `write` —— 写入文件

```c
ssize_t write(int fd, const void *buf, size_t count);
```

- **fd**：文件描述符（`1`=stdout，`2`=stderr，或 `open` 返回的 fd）
- **buf**：要写入的数据缓冲区
- **count**：期望写入的字节数
- **返回值**：实际写入的字节数，可根据返回值判断是否完整写入

**示例**：

```c
char buf[] = "hello POSIX";
int len = write(fd, buf, sizeof(buf));
```

---

### 4.3 `read` —— 读取文件

```c
ssize_t read(int fd, void *buf, size_t count);
```

- **fd**：文件描述符（如 `0`=stdin）
- **buf**：存放读取数据的缓冲区
- **count**：期望读取的最大字节数
- **返回值**：实际读取的字节数，`0` 表示 EOF，`-1` 表示出错

**示例**：

```c
char buf2[16];
memset(buf2, 0, sizeof(buf2));
int n = read(0, buf2, sizeof(buf2));  // 从标准输入读取
write(1, buf2, n);                     // 写到标准输出
```

---

### 4.4 `close` —— 关闭文件

```c
int close(int fd);
```

打开的文件使用完毕后必须关闭，以释放系统资源。

---

## 五、系统调用 vs 标准库函数

| 对比维度 | 系统调用（如 `open`/`write`） | 标准库函数（如 `fopen`/`fprintf`） |
|---------|-------------------------------|-----------------------------------|
| 所属层次 | 内核层 | 用户层（封装了系统调用） |
| 缓冲区 | **无用户态缓冲** | **有用户态缓冲（FILE *）** |
| 文件标识 | 整数文件描述符 `int fd` | `FILE *` 指针 |
| 可移植性 | POSIX 标准，Unix 系通用 | ISO C 标准，跨平台 |
| 性能 | 直接与内核交互，无额外缓冲 | 缓冲 I/O 减少系统调用次数 |

---

## 六、完整代码逻辑流程

```
1. open("test4.txt", O_WRONLY | O_CREAT, 0660)  →  获取文件描述符 fd（通常为 3）
2. write(fd, buf, sizeof(buf))                   →  将 "hello POSIX\0" 写入文件
3. close(fd)                                     →  关闭文件，释放描述符
```

---

## 七、关键注意点

1. **文件权限用八进制**：`0660` 前面的 `0` 表示八进制，不能省略。
2. **写入字节数需校验**：`write` 的返回值可能小于 `count`，实际编程中应做判断。
3. **文件用完要关闭**：用 `close(fd)` 释放资源，避免文件描述符泄漏。
4. **缓冲区初始化**：`read` 前建议用 `memset` 清零，避免读到脏数据。
5. **错误处理**：`open` 返回 `-1` 时说明打开失败，应检查并处理。
