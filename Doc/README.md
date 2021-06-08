[![Documentation Status](https://readthedocs.org/projects/solana-cpp/badge/?version=latest)](https://solana-cpp.readthedocs.io/en/latest/?badge=latest)

# How to build documentation

It is assumed that this documentation will be hosted on the website https://readthedocs.org/.
For assembly of documentation the **sphinx** generator is used (http://sphinx-doc.org).
The format of the source files is `*.rst` (**reStructuredText**) or `*.md` (**Markdown**).

Information on installing the sphinx engine and how to assemble a project with documentation can be found at:
https://docs.readthedocs.io/en/stable/intro/getting-started-with-sphinx.html


**TL;DR**

To build an HTML version of the documentation on your computer:

```sh
   $ pip install sphinx
   $ pip install recommonmark
   $ pip install sphinx-rtd-theme
   $ cd /path/to/cloned/project
   $ cd docs
   $ make html
```

Go to `build/html` directory and open `index.html` file in your browser.

You have also some other formats to build. Run `make help` to see those options.


# Documentation online

The actual online version of the documentation you can find at:

https://solana-cpp.readthedocs.io/en/latest/
