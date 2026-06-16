#!/bin/bash

# 基准测试脚本 v2
# h1: TASK_SIZE=102400, TID_MAX=1-16,32
# h1plus: TASK_SIZE=1024, TID_MAX=1-16,32
# h1plus: TASK_SIZE=102400, TID_MAX=1-16,32

RESULT_FILE="./h1_result.md"
BASE_DIR="/home/lmq20233547/All_C-code-of-lmq/Three_down/0613线程"
SOURCE_DIR="/home/lmq20233547/linux-7.0.10"

# 确认源目录存在
if [ ! -d "$SOURCE_DIR" ]; then
    echo "错误: $SOURCE_DIR 不存在"
    exit 1
fi

# 清理缓存函数
clear_cache() {
    sync
    echo 3 | sudo tee /proc/sys/vm/drop_caches > /dev/null 2>&1
    sleep 0.5
}

# 追加标题到结果文件
echo "" >> "$RESULT_FILE"
echo "---" >> "$RESULT_FILE"
echo "" >> "$RESULT_FILE"
echo "## 第二轮基准测试（$(date '+%Y-%m-%d %H:%M:%S')）" >> "$RESULT_FILE"
echo "" >> "$RESULT_FILE"

# ============================================================
# Part 1: h1, TASK_SIZE=102400, TID_MAX=1..16,32
# ============================================================
echo "### h1（忙等待版）TASK_SIZE=102400" >> "$RESULT_FILE"
echo "" >> "$RESULT_FILE"
echo "| TID_MAX | 消费线程数 | real(s) | user(s) | sys(s) | 文件数 | 目录数 | 总行数 |" >> "$RESULT_FILE"
echo "|---------|-----------|---------|---------|--------|--------|--------|--------|" >> "$RESULT_FILE"

cd "$BASE_DIR"

for TID in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 32; do
    echo "=== h1 TASK_SIZE=102400 TID_MAX=$TID ==="

    # 编译 h1（TASK_SIZE 已在源码中改为 102400）
    # 修改 TID_MAX
    sed -i "s/#define TID_MAX .*/#define TID_MAX $TID/" h1.c
    gcc -o h1 h1.c -lpthread -O2 2>&1
    if [ $? -ne 0 ]; then
        echo "编译失败 TID_MAX=$TID" | tee -a "$RESULT_FILE"
        continue
    fi

    clear_cache
    OUTPUT=$(/usr/bin/time -f "%e %U %S" ./h1 2>&1)
    REAL=$(echo "$OUTPUT" | tail -1 | awk '{print $1}')
    USR=$(echo "$OUTPUT" | tail -1 | awk '{print $2}')
    SYS=$(echo "$OUTPUT" | tail -1 | awk '{print $3}')
    FC=$(echo "$OUTPUT" | grep "文件数" | grep -oP '\d+')
    DC=$(echo "$OUTPUT" | grep "目录数" | grep -oP '\d+')
    LC=$(echo "$OUTPUT" | grep "总行数" | grep -oP '\d+')
    CONSUMER=$((TID - 1))

    echo "| $TID | $CONSUMER | $REAL | $USR | $SYS | $FC | $DC | $LC |" >> "$RESULT_FILE"
    echo "  结果: real=$REAL user=$USR sys=$SYS"
done

# 恢复 h1.c 的 TID_MAX
sed -i "s/#define TID_MAX .*/#define TID_MAX 64/" h1.c

# ============================================================
# Part 2: h1plus, TASK_SIZE=1024, TID_MAX=1..16,32
# ============================================================
echo "" >> "$RESULT_FILE"
echo "### h1plus（条件变量版）TASK_SIZE=1024" >> "$RESULT_FILE"
echo "" >> "$RESULT_FILE"
echo "| TID_MAX | 消费线程数 | real(s) | user(s) | sys(s) | 文件数 | 目录数 | 总行数 |" >> "$RESULT_FILE"
echo "|---------|-----------|---------|---------|--------|--------|--------|--------|" >> "$RESULT_FILE"

for TID in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 32; do
    echo "=== h1plus TASK_SIZE=1024 TID_MAX=$TID ==="

    sed -i "s/#define TID_MAX .*/#define TID_MAX $TID/" h1plus.c
    sed -i "s/#define TASK_SIZE .*/#define TASK_SIZE 1024/" h1plus.c
    gcc -o h1plus h1plus.c -lpthread -O2 2>&1
    if [ $? -ne 0 ]; then
        echo "编译失败 TID_MAX=$TID" | tee -a "$RESULT_FILE"
        continue
    fi

    clear_cache
    OUTPUT=$(/usr/bin/time -f "%e %U %S" ./h1plus 2>&1)
    REAL=$(echo "$OUTPUT" | tail -1 | awk '{print $1}')
    USR=$(echo "$OUTPUT" | tail -1 | awk '{print $2}')
    SYS=$(echo "$OUTPUT" | tail -1 | awk '{print $3}')
    FC=$(echo "$OUTPUT" | grep "文件数" | grep -oP '\d+')
    DC=$(echo "$OUTPUT" | grep "目录数" | grep -oP '\d+')
    LC=$(echo "$OUTPUT" | grep "总行数" | grep -oP '\d+')
    CONSUMER=$((TID - 1))

    echo "| $TID | $CONSUMER | $REAL | $USR | $SYS | $FC | $DC | $LC |" >> "$RESULT_FILE"
    echo "  结果: real=$REAL user=$USR sys=$SYS"
done

# ============================================================
# Part 3: h1plus, TASK_SIZE=102400, TID_MAX=1..16,32
# ============================================================
echo "" >> "$RESULT_FILE"
echo "### h1plus（条件变量版）TASK_SIZE=102400" >> "$RESULT_FILE"
echo "" >> "$RESULT_FILE"
echo "| TID_MAX | 消费线程数 | real(s) | user(s) | sys(s) | 文件数 | 目录数 | 总行数 |" >> "$RESULT_FILE"
echo "|---------|-----------|---------|---------|--------|--------|--------|--------|" >> "$RESULT_FILE"

for TID in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 32; do
    echo "=== h1plus TASK_SIZE=102400 TID_MAX=$TID ==="

    sed -i "s/#define TID_MAX .*/#define TID_MAX $TID/" h1plus.c
    sed -i "s/#define TASK_SIZE .*/#define TASK_SIZE 102400/" h1plus.c
    gcc -o h1plus h1plus.c -lpthread -O2 2>&1
    if [ $? -ne 0 ]; then
        echo "编译失败 TID_MAX=$TID" | tee -a "$RESULT_FILE"
        continue
    fi

    clear_cache
    OUTPUT=$(/usr/bin/time -f "%e %U %S" ./h1plus 2>&1)
    REAL=$(echo "$OUTPUT" | tail -1 | awk '{print $1}')
    USR=$(echo "$OUTPUT" | tail -1 | awk '{print $2}')
    SYS=$(echo "$OUTPUT" | tail -1 | awk '{print $3}')
    FC=$(echo "$OUTPUT" | grep "文件数" | grep -oP '\d+')
    DC=$(echo "$OUTPUT" | grep "目录数" | grep -oP '\d+')
    LC=$(echo "$OUTPUT" | grep "总行数" | grep -oP '\d+')
    CONSUMER=$((TID - 1))

    echo "| $TID | $CONSUMER | $REAL | $USR | $SYS | $FC | $DC | $LC |" >> "$RESULT_FILE"
    echo "  结果: real=$REAL user=$USR sys=$SYS"
done

# 恢复 h1plus.c 的原始值
sed -i "s/#define TID_MAX .*/#define TID_MAX 10/" h1plus.c
sed -i "s/#define TASK_SIZE .*/#define TASK_SIZE 1024/" h1plus.c

echo ""
echo "=== 所有基准测试完成！结果已追加到 $RESULT_FILE ==="
