with open("test2.txt", "w") as file:
    block = """
    data science is amazing data science is challenging data science is fun 
    machine learning and deep learning are subsets of artificial intelligence 
    big data analytics involves data cleaning data transformation and data visualization 
    data science is about extracting knowledge from data using programming 
    data data data data science science science science is is is is amazing amazing amazing amazing
    ai and ml are driving innovation in data-driven industries 
    python and r are popular programming languages for data science 
    statistics and probability form the foundation of data science 
    data science applications include healthcare finance marketing and more 
    """
    cleaned_block = ' '.join(block.split())
    file.write(cleaned_block * 1000)