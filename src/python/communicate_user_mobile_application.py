from flask import Flask, jsonify

app = Flask(__name__)

@app.route('/info', methods=['GET'])
def get_informations():

    in_motion = True
    battery_level = 75

    status = 'In motion' if in_motion else 'Stopped'
    batery = f'{battery_level}%'

    informations = {
        'status': 'Em movimento',
        'battery': '75%'
    }
    
    return jsonify(informations)

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000, debug=True)