from flask import Flask, Response
import subprocess

app = Flask(__name__)

def get_process_info(process_name):
    pid = subprocess.getoutput(f"pgrep -f {process_name}")
    if pid:
        stats = subprocess.getoutput(f"ps -p {pid} -o %cpu,%mem").splitlines()[1].split()
        cpu_usage, mem_usage = stats[0], stats[1]
        return cpu_usage, mem_usage
    return None, None

@app.route('/metrics')
def metrics():
    cpu_usage, mem_usage = get_process_info("firefox")
    if cpu_usage and mem_usage:
        metrics = [
            f"# HELP process_cpu_usage CPU usage of the process",
            f"# TYPE process_cpu_usage gauge",
            f"process_cpu_usage{{process=\"firefox\"}} {cpu_usage}",
            f"# HELP process_mem_usage Memory usage of the process",
            f"# TYPE process_mem_usage gauge",
            f"process_mem_usage{{process=\"firefox\"}} {mem_usage}",
        ]
        return Response('\n'.join(metrics), mimetype='text/plain')
    return Response("Error: Process not found", status=404, mimetype='text/plain')

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5001)
