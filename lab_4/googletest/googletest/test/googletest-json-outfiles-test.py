#!/usr/bin/env python
# Copyright 2018, Google Inc.
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are
# met:
#
#     * Redistributions of source code must retain the above copyright
# notice, this list of conditions and the following disclaimer.
#     * Redistributions in binary form must reproduce the above
# copyright notice, this list of conditions and the following disclaimer
# in the documentation and/or other materials provided with the
# distribution.
#     * Neither the name of Google Inc. nor the names of its
# contributors may be used to endorse or promote products derived from
# this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
# A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
# OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
# SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
# LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

"""Unit tests for the gtest_json_output module."""

import json
import os
from googletest.test import gtest_json_test_utils
from googletest.test import gtest_test_utils

GTEST_OUTPUT_SUBDIR = 'json_outfiles'
GTEST_OUTPUT_1_TEST = 'gtest_xml_outfile1_test_'
GTEST_OUTPUT_2_TEST = 'gtest_xml_outfile2_test_'

EXPECTED_1 = {
    'tests': 1,
    'failures': 0,
    'disabled': 0,
    'errors': 0,
    'time': '*',
    'timestamp': '*',
    'name': 'AllTests',
    'testsuites': [{
        'name': 'PropertyOne',
        'tests': 1,
        'failures': 0,
        'disabled': 0,
        'errors': 0,
        'time': '*',
        'timestamp': '*',
        'testsuite': [{
            'name': 'TestSomeProperties',
            'file': 'gtest_xml_outfile1_test_.cc',
            'line': 41,
            'status': 'RUN',
            'result': 'COMPLETED',
            'time': '*',
            'timestamp': '*',
            'classname': 'PropertyOne',
            'SetUpProp': '1',
            'TestSomeProperty': '1',
            'TearDownProp': '1',
        }],
    }],
}

EXPECTED_2 = {
    'tests': 1,
    'failures': 0,
    'disabled': 0,
    'errors': 0,
    'time': '*',
    'timestamp': '*',
    'name': 'AllTests',
    'testsuites': [{
        'name': 'PropertyTwo',
        'tests': 1,
        'failures': 0,
        'disabled': 0,
        'errors': 0,
        'time': '*',
        'timestamp': '*',
        'testsuite': [{
            'name': 'TestInt64ConvertibleProperties',
            'file': 'gtest_xml_outfile2_test_.cc',
            'line': 43,
            'status': 'RUN',
            'result': 'COMPLETED',
            'timestamp': '*',
            'time': '*',
            'classname': 'PropertyTwo',
            'SetUpProp': '2',
            'TestFloatProperty': '3.25',
            'TestDoubleProperty': '4.75',
            'TestSizetProperty': '5',
            'TestBoolProperty': 'true',
            'TestCharProperty': 'A',
            'TestInt16Property': '6',
            'TestInt32Property': '7',
            'TestInt64Property': '8',
            'TestEnumProperty': '9',
            'TestAtomicIntProperty': '10',
            'TearDownProp': '2',
        }],
    }],
}


class GTestJsonOutFilesTest(gtest_test_utils.TestCase):
  """Unit tests for Google Test's JSON output functionality."""

  def setUp(self):
    # We want the trailing '/' that the last "" provides in os.path.join, for
    # telling Google Test to create an output directory instead of a single file
    # for xml output.
    self.output_dir_ = os.path.join(
        gtest_test_utils.GetTempDir(), GTEST_OUTPUT_SUBDIR, ''
    )
    self.DeleteFilesAndDir()

  def tearDown(self):
    self.DeleteFilesAndDir()

  def DeleteFilesAndDir(self):
    try:
      os.remove(os.path.join(self.output_dir_, GTEST_OUTPUT_1_TEST + '.json'))
    except os.error:
      pass
    try:
      os.remove(os.path.join(self.output_dir_, GTEST_OUTPUT_2_TEST + '.json'))
    except os.error:
      pass
    try:
      os.rmdir(self.output_dir_)
    except os.error:
      pass

  def testOutfile1(self):
    self._TestOutFile(GTEST_OUTPUT_1_TEST, EXPECTED_1)

  def testOutfile2(self):
    self._TestOutFile(GTEST_OUTPUT_2_TEST, EXPECTED_2)

  def _TestOutFile(self, test_name, expected):
    gtest_prog_path = gtest_test_utils.GetTestExecutablePath(test_name)
    command = [gtest_prog_path, '--gtest_output=json:%s' % self.output_dir_]
    p = gtest_test_utils.Subprocess(
        command, working_dir=gtest_test_utils.GetTempDir()
    )
    self.assertTrue(p.exited)
    self.assertEqual(0, p.exit_code)

    output_file_name1 = test_name + '.json'
    output_file1 = os.path.join(self.output_dir_, output_file_name1)
    output_file_name2 = 'lt-' + output_file_name1
    output_file2 = os.path.join(self.output_dir_, output_file_name2)
    self.assertTrue(
        os.path.isfile(output_file1) or os.path.isfile(output_file2),
        output_file1,
    )

    if os.path.isfile(output_file1):
      with open(output_file1) as f:
        actual = json.load(f)
    else:
      with open(output_file2) as f:
        actual = json.load(f)
    self.assertEqual(expected, gtest_json_test_utils.normalize(actual))


if __name__ == '__main__':
  os.environ['GTEST_STACK_TRACE_DEPTH'] = '0'
  gtest_test_utils.Main()
