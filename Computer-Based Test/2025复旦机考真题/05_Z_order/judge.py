from hashlib import sha256
from pathlib import Path
import random
import subprocess
import sys

ROOT = Path(__file__).resolve().parent
SRC = ROOT / "main.cpp"
EXE = ROOT / "main.exe"

if "--hidden" in sys.argv:
    subprocess.run([sys.executable, str(ROOT.parent.parent / "hidden_judge.py"), ROOT.name], check=False)
    raise SystemExit


def digest(text):
    return sha256(text.strip().encode()).hexdigest()


def query_case(n, queries):
    return f"{n} {len(queries)}\n" + "\n".join(f"{x} {y}" for x, y in queries) + "\n"


rng = random.Random(25)
large_queries = [(rng.randint(1, 1 << 25), rng.randint(1, 1 << 25)) for _ in range(1000)]
PUBLIC = [
    (query_case(2, [(1, 1), (1, 3), (3, 1), (4, 4)]), "c802575273c825b4a811633c5d698638ab3556489ed516685a52392e696fda00"),
    (query_case(3, [(1, 8), (8, 1), (5, 6), (4, 4)]), "3c86d1a2ee2f727d86847f083ad762369833574c9d9f2372d9d2127b274661c8"),
    (query_case(25, large_queries), "ac87ea5616f7b8fa63ba5c3473a9c6ca142788615f3c773810183c3aaaa51ae4"),
]


def run_case(data, timeout=3.0):
    try:
        p = subprocess.run([str(EXE)], input=data, text=True, capture_output=True, timeout=timeout)
    except subprocess.TimeoutExpired:
        return "TLE", ""
    if p.returncode != 0:
        return "RE", ""
    return "OK", p.stdout


def main():
    if not SRC.exists():
        print("未找到 main.cpp，请先在本目录创建代码文件。")
        return
    build = subprocess.run(["g++", str(SRC), "-std=c++17", "-O2", "-o", str(EXE)], text=True, capture_output=True)
    if build.returncode:
        print("编译失败：")
        print(build.stderr)
        return
    print("编译成功。公开样例评测：")
    for i, (data, expected_digest) in enumerate(PUBLIC, 1):
        status, out = run_case(data)
        result = "通过" if status == "OK" and digest(out) == expected_digest else status if status != "OK" else "答案错误"
        print(f"样例 {i}: {result}")
    print("仅显示公开样例结果；本脚本不运行、也不显示隐藏评测。")


if __name__ == "__main__":
    main()
