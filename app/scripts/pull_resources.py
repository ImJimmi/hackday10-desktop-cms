from numpy import source
import boto3
from botocore.client import Config
from dotenv import load_dotenv
import os
from pprint import pprint


def create_parameters():
    load_dotenv()

    return {
        'bucket': 'hackday10.desktop.cms',
        'region': 'eu-west-2',
        'access_key': os.getenv('aws_access_key_id'),
        'secret_key': os.getenv('aws_secret_access_key'),
    }


def create_client(parameters):
    return boto3.client(
        's3',
        config=Config(s3={
            'addressing_style': 'path'
        }),
        region_name=parameters['region'],
        aws_access_key_id=parameters['access_key'],
        aws_secret_access_key=parameters['secret_key']
    )


if __name__ == '__main__':
    parameters = create_parameters()
    s3_client = create_client(parameters)

    response = s3_client.list_objects_v2(Bucket=parameters['bucket'])

    for object in response['Contents']:
        object_key = object['Key']
        destination_file = 'app/resources/' + object_key

        print('Downloading "' + object_key +
              '" to "' + destination_file + '"...')

        with open(destination_file, 'wb') as file:
            s3_client.download_file(
                parameters['bucket'],
                object_key,
                file.name
            )
