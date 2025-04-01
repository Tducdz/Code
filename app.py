from flask import Flask, render_template, request

app = Flask(__name__)

# Dữ liệu mẫu
dishes = [
    {"name": "Món A", "ingredients": ["thịt gà", "rau cải"]},
    {"name": "Món B", "ingredients": ["cá", "nấm"]},
    {"name": "Món C", "ingredients": ["đậu hũ", "rau muống"]}
]

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/search', methods=['POST'])
def search():
    ingredients = request.form.getlist('ingredients')
    # Lọc món ăn theo nguyên liệu
    filtered_dishes = [dish for dish in dishes if all(item in dish['ingredients'] for item in ingredients)]
    return render_template('results.html', dishes=filtered_dishes)

if __name__ == '__main__':
    app.run(debug=True)
