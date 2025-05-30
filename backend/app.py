from flask import Flask, request, jsonify
from flask_cors import CORS
import os

app = Flask(__name__)
CORS(app)

@app.route('/api/status', methods=['GET'])
def get_status():
    return jsonify({"pompa": "wylaczona", "wilgotnosc": 540})

@app.route('/api/pompa', methods=['POST'])
def toggle_pump():
    action = request.json.get("akcja")
    print(f"Pompa -> {action}")
    return jsonify({"status": f"Pompa {action}"})

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)